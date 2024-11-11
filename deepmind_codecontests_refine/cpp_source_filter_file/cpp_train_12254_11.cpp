#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using piii = pair<int, pii>;
using plll = pair<ll, pll>;
using pib = pair<int, bool>;
using pdi = pair<double, int>;
using pid = pair<int, double>;
using ld = long double;
using piiii = pair<pii, pii>;
int n, arr[1000001], idx[1000001];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    idx[arr[i]] = i;
  }
  int t = 0;
  for (int i = 1; i <= n; i++) {
    if (arr[i] != i) {
      arr[idx[i]] = arr[i];
      idx[arr[i]] = idx[i];
      t++;
    }
  }
  if (t % 2)
    cout << "Petr"
         << "\n";
  else
    cout << "Um_nik"
         << "\n";
  return 0;
}
