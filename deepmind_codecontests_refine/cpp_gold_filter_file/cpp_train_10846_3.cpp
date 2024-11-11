#include <bits/stdc++.h>
using namespace std;
void pv(vector<int> v) {
  for (int i = 0; i < v.size(); ++i) {
    cout << v[i] << " ";
  }
  cout << "" << endl;
}
void pa(int a[], int n, int p) {
  for (int i = p; i < n + p; ++i) {
    cout << a[i] << " ";
  }
  cout << "" << endl;
}
const double pi = 3.141592653589793238;
const int inf = 1000000;
int main() {
  ios ::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int n, gcd = 0, temp, ans, mx = -1, l;
  cin >> n;
  long long int q[n + 1];
  for (int i = 1; i <= n; i += 1) cin >> q[i];
  std::vector<long long int> v[64];
  for (int i = 1; i <= n; i += 1) {
    temp = 1LL << 62;
    for (int j = 62; j >= 0; j -= 1) {
      if (q[i] % temp == 0) {
        v[j].push_back(q[i]);
        break;
      }
      temp = temp >> 1;
    }
  }
  for (int i = 0; i <= 62; i += 1) {
    if (v[i].size() > mx) mx = v[i].size(), ans = i;
  }
  cout << n - mx << endl;
  for (int i = 0; i <= 62; i += 1) {
    if (i != ans) {
      l = v[i].size();
      for (int j = 0; j <= l - 1; j += 1) cout << v[i][j] << " ";
    }
  }
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
}
