#include <bits/stdc++.h>
using namespace std;
const int MAX_N = int(1e5) + 10;
int n, new_pos(int(1e9) + 1);
pair<int, int> a[MAX_N], b[MAX_N];
map<pair<int, int>, int> idx;
set<int> S;
bool is_lucky_number(int x) {
  for (; x > 0; x /= 10) {
    if (x % 10 != 4 && x % 10 != 7) {
      return false;
    }
  }
  return true;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    if (S.count(x)) {
      a[i].first = x;
      a[i].second = new_pos++;
      idx[make_pair(x, new_pos - 1)] = i;
    } else {
      S.insert(x);
      a[i].first = a[i].second = x;
      idx[make_pair(x, x)] = i;
    }
    b[i] = a[i];
  }
  sort(b, b + n);
  bool same = true;
  for (int i = 0; i < n && same; i++) {
    same &= a[i].first == b[i].first;
  }
  if (same) {
    return puts("0"), 0;
  }
  pair<int, int> number;
  int pos = -1;
  for (int i = 0; i < n; i++) {
    if (is_lucky_number(b[i].first)) {
      number = b[i];
      pos = i;
      break;
    }
  }
  if (pos == -1) {
    return puts("-1"), 0;
  }
  vector<pair<int, int> > v;
  for (int i = 0; i < n; i++) {
    if (i != pos) {
      int j = idx[number];
      if (j != i) {
        swap(a[i], a[j]);
        idx[a[i]] = i;
        idx[a[j]] = j;
        v.push_back(make_pair(i, j));
      }
      j = idx[b[i]];
      if (j != i) {
        swap(a[i], a[j]);
        idx[a[i]] = i;
        idx[a[j]] = j;
        v.push_back(make_pair(i, j));
      }
    }
  }
  printf("%d\n", (int)v.size());
  for (__typeof((v).begin()) e = (v).begin(); e != (v).end(); ++e) {
    printf("%d %d\n", e->first + 1, e->second + 1);
  }
}
