#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, k;
  cin >> n >> k;
  if (k >= (n) * (n - 1) / 2) {
    cout << "no solution" << endl;
    return;
  }
  for (int i = 0; i < n; i++) cout << "0 " << i << endl;
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}
