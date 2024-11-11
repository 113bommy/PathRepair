#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
int main() {
  ios::sync_with_stdio(false);
  int n, s;
  cin >> n >> s;
  if (s < n * 2)
    cout << "NO" << endl;
  else {
    cout << "YES" << endl;
    for (int i = 1; i < n; i++) cout << 2 << " ";
    cout << s - (n - 1) * 2 << endl;
    cout << 1 << endl;
  }
}
