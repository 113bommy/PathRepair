#include <bits/stdc++.h>
using namespace std;
void yay(long long int flag) {
  if (flag == 0)
    cout << "NO";
  else
    cout << "YES";
  cout << endl;
}
template <typename T>
void unq(vector<T>& vec) {
  sort(vec.begin(), vec.end());
  vec.erase(unique(vec.begin(), vec.end()), vec.end());
}
template <typename T>
void dsp(vector<T>& v, long long int n, long long int a) {
  long long int i;
  for (i = 0; i < n; ++i) {
    cout << v[i] << " ";
  }
  cout << "\n";
}
template <typename T>
void input(vector<T>& v, long long int n) {
  long long int i;
  T x;
  for (i = 0; i < n; ++i) {
    cin >> x;
    v.push_back(x);
  }
}
int eve(long long int x) {
  if (x % 2 == 0) return 1;
  return 0;
}
const long long int inf = 1e17 + 7;
const int infi = 1e9 + 7;
const long long int dd = 8e7 + 7;
const long long int mod = 1e9 + 7;
void solve() {
  double a, b, d;
  cin >> d;
  if (d * d < 4 * d) {
    cout << "N";
    return;
  }
  cout << "Y"
       << " ";
  a = d * d - 4 * d;
  a = sqrt(a);
  b = d - a;
  b = b / 2;
  cout << fixed << setprecision(8) << d - b << " " << fixed << setprecision(8)
       << b;
}
int main() {
  ios_base::sync_with_stdio(false);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
    cout << "\n";
  }
}
