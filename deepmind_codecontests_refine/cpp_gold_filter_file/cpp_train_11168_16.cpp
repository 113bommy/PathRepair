#include <bits/stdc++.h>
using namespace std;
int pre[1010];
int n;
int main() {
  cin >> n;
  for (int i = 2; i <= n; ++i) {
    cout << "? " << 1 << " " << i << endl;
    cin >> pre[i];
  }
  cout << "? " << 2 << " " << n << endl;
  int tmp;
  cin >> tmp;
  pre[1] = pre[n] - tmp;
  cout << "! ";
  for (int i = 1; i <= n; ++i) cout << pre[i] - pre[i - 1] << " ";
  cout << endl;
  return 0;
}
