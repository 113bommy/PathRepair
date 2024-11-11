#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9 + 123, MAXN = 3e5, MEGAINF = 1e18 + 228;
template <class T>
inline istream& operator>>(istream& in, vector<T>& a) {
  for (auto& i : a) in >> i;
  return in;
}
template <class T>
inline ostream& operator<<(ostream& out, vector<T>& a) {
  for (auto i : a) out << i << " ";
  return out;
}
template <class T, class U>
inline istream& operator>>(istream& in, vector<pair<T, U>>& a) {
  for (auto& i : a) in >> i.first >> i.second;
  return in;
}
template <class T, class U>
inline ostream& operator<<(ostream& out, vector<pair<T, U>>& a) {
  for (auto& i : a) out << i.first << " " << i.second << "\n";
}
long long get(long long ind) {
  cout << "? " << ind + 1 << endl;
  long long val;
  cin >> val;
  return val;
}
signed main() {
  setlocale(LC_ALL, "rus");
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n;
  cin >> n;
  long long val_l = get(0), val_r = get(n / 2);
  if ((val_l - val_r) % 2) return cout << "! -1", 0;
  long long val_b = val_l - val_r;
  long long l = 0, r = n / 2 - 1;
  while (r - l > 1) {
    long long mid = l + r >> 1;
    long long one = get(mid), two = get(mid + n / 2);
    long long b = one - two;
    if (b == 0) return cout << "! " << mid + 1, 0;
    if (val_b > 0 && b < 0)
      r = mid;
    else if (val_b > 0 && b > 0)
      l = mid;
    else if (val_b < 0 && b < 0)
      l = mid;
    else if (val_b < 0 && b > 0)
      r = mid;
  }
}
