#include <bits/stdc++.h>
using namespace std;
int ans[1234567];
int main() {
  int n, t;
  scanf("%d", &n);
  vector<pair<int, int> > a, b;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &t);
    a.push_back(make_pair(t, i));
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &t);
    b.push_back(make_pair(t, i));
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  reverse(b.begin(), b.end());
  for (int i = 0; i < n; ++i) {
    int index = b[i].second;
    ans[index] = a[i].first;
  }
  for (int i = 0; i < n; ++i) {
    printf("%d ", a[i]);
  }
  puts("");
}
