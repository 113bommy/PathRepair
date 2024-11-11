#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6 + 6;
vector<int> pac, ast;
char str[MAX];
int n, pref[MAX], best[MAX];
inline int query(int left, int right) {
  if (left > right) {
    return 0;
  }
  return pref[right] - pref[left - 1];
}
bool ok(int limit) {
  for (int i = int(0); i < int(pac.size()); i++) {
    if (query(best[i] + 1, pac[i] - limit - 1) > 0) {
      return false;
    } else if (query(best[i] + 1, pac[i] - 1) == 0) {
      best[i + 1] = pac[i] + limit;
    } else if (i > 0 && query(best[i - 1] + 1, pac[i] - limit - 1) == 0) {
      best[i + 1] = max(pac[i - 1] + limit, pac[i]);
    } else {
      best[i + 1] = pac[i];
    }
  }
  return query(best[pac.size()], n) == 0;
}
int main() {
  scanf("%d", &n);
  scanf("%s", str);
  for (int i = int(0); i < int(n); i++) {
    pref[i + 1] = pref[i];
    if (str[i] == '*') {
      pref[i + 1]++;
      ast.push_back(i + 1);
    } else if (str[i] == 'P') {
      pac.push_back(i + 1);
    }
  }
  if (pac.size() == 1) {
    int to_left = lower_bound(ast.begin(), ast.end(), pac[0]) - ast.begin();
    int to_right = ast.size() - to_left;
    if (to_left > to_right) {
      printf("%d %d\n", to_left, pac[0] - ast[0]);
    } else if (to_right > to_left) {
      printf("%d %d\n", to_right, ast.back() - pac[0]);
    } else {
      printf("%d %d\n", to_left, min(pac[0] - ast[0], ast.back() - pac[0]));
    }
  } else {
    int left = 1, right = (int)1e6;
    int best_time = -1;
    while (left <= right) {
      int mid = (left + right) / 2;
      if (ok(mid)) {
        best_time = mid;
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    printf("%d %d\n", (int)ast.size(), best_time);
  }
  return 0;
}
