#include <bits/stdc++.h>
using namespace std;
void test_case() {
  int n;
  cin >> n;
  if (n == 1) {
    cout << "-1\n";
    return;
  }
  for (int i = 0; i < n - 1; ++i) {
    cout << 3;
  }
  cout << 4 << "\n";
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    test_case();
  }
  return 0;
}
