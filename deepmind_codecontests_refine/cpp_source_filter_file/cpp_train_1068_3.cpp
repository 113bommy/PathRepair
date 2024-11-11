#include <bits/stdc++.h>
using namespace std;
void test_case() {
  int n, k;
  cin >> n >> k;
  set<int> s;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    s.insert(a);
  }
  int len = s.size();
  if (k == 1)
    cout << (len == 1 ? -1 : 1) << '\n';
  else if (len < k)
    cout << 1 << '\n';
  else
    cout << (len + k - 1) / k << '\n';
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int Case = 1;
  cin >> Case;
  for (int i = 0; i < Case; i++) {
    test_case();
  }
  return 0;
}
