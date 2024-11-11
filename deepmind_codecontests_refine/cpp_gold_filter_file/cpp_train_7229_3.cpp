#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
void test_case() {
  int a, b;
  cin >> a >> b;
  cout << ((min(a, b) + 1) & 1 ? "Malvika" : "Akshat") << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tt = 1;
  while (tt--) {
    test_case();
  }
  return 0;
}
