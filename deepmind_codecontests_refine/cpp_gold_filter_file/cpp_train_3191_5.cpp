#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> m;
  for (int i = 0; i < n; i++) {
    int a, b;
    scanf("%d:%d", &a, &b);
    m.push_back(a * 60 + b);
    m.push_back(a * 60 + b + 24 * 60);
  }
  sort(m.begin(), m.end());
  int ans = 0;
  for (int i = 1; i < m.size(); ++i) {
    if (m[i] - m[i - 1] > ans) ans = m[i] - m[i - 1];
  }
  ans--;
  printf("%02d:%02d\n", ans / 60, ans % 60);
}
