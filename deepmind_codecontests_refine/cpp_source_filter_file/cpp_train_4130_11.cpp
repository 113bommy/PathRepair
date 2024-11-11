#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using vi = vector<int>;
const ll INF = 1e9 + 7;
bool elem_(vi& a, int elem) {
  for (size_t i = 0; i < a.size(); i++) {
    if (a[i] == elem) {
      return true;
    }
  }
  return false;
}
void solution() {
  int n;
  scanf("%d", &n);
  vi a(n);
  for (size_t i = 0; i < a.size(); i++) {
    scanf("%d", &a[i]);
  }
  vi ans;
  for (int i = a.size() - 1; i != 0; i--) {
    if (ans.empty()) {
      ans.push_back(a[i]);
    } else if (!elem_(ans, a[i])) {
      ans.push_back(a[i]);
    }
  }
  reverse(ans.begin(), ans.end());
  printf("%d\n", ans.size());
  for (auto it : ans) {
    printf("%d ", it);
  }
  printf("\n");
}
int main() {
  solution();
  return 0;
}
