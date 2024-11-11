#include <bits/stdc++.h>
using namespace std;
string ys = "YES", no = "NO", st;
int di[8] = {1, 0, -1, 0, -1, 1, -1, 1};
int dj[8] = {0, -1, 0, 1, 1, 1, -1, -1};
const int N = 1.5 * 10000000 + 16;
const long long int OO = 1e18;
long long int mod = 1e9 + 7;
void fast() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
int main() {
  fast();
  int q;
  q = 1;
  while (q--) {
    int n;
    cin >> n;
    if (!(n & 1)) return cout << -1 << "\n", 0;
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) {
      a[i] = i;
      b[i] = i;
      c[i] = (2 * i) % n;
    }
    for (auto i : a) cout << i << " ";
    cout << "\n";
    for (auto i : b) cout << i << " ";
    cout << "\n";
    for (auto i : c) cout << i << " ";
    cout << "\n";
  }
}
