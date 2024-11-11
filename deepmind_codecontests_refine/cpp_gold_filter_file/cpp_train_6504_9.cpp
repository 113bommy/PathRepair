#include <bits/stdc++.h>
using namespace std;
void init() {}
int n, a;
int all[5000];
int max_to_add[5000];
int added[5000];
int main() {
  init();
  scanf("%d", &n);
  for (int i = (2); i < ((1 << (n + 1))); ++i) {
    scanf("%d", &all[i]);
  }
  vector<int> l;
  for (int i = ((1 << n)); i < ((1 << (n + 1))); ++i) {
    int cur = i;
    int sum = 0;
    while (cur) {
      sum += all[cur];
      cur /= 2;
    }
    l.push_back(sum);
  }
  int mx = *max_element(l.begin(), l.end());
  for_each(max_to_add, max_to_add + 5000, [&](int &a) { a = mx; });
  for (int i = ((1 << n)); i < ((1 << (n + 1))); ++i) {
    int cur = i;
    int sum = 0;
    while (cur) {
      max_to_add[cur] = min(max_to_add[cur], mx - l[i - (1 << n)]);
      cur /= 2;
    }
  }
  int ans = 0;
  for (int i = (2); i < ((1 << (n + 1))); ++i) {
    added[i] += added[i / 2];
    ans += max_to_add[i] - added[i];
    added[i] = max_to_add[i];
  }
  cout << ans << "\n";
  return 0;
}
