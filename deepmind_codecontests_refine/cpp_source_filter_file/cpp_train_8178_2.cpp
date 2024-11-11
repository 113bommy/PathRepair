#include <bits/stdc++.h>
using namespace std;
inline int in() {
  int x;
  cin >> x;
  return x;
}
template <typename T>
istream &operator>>(istream &in, vector<T> &vec) {
  for (int i = 0; i < vec.size(); ++i) in >> vec[i];
  return in;
}
template <typename T>
ostream &operator<<(ostream &out, const vector<T> &vec) {
  for (int i = 0; i < vec.size(); ++i) out << vec[i] << " ";
  return out;
}
int main() {
  int n = in();
  vector<long long> a(n + 1);
  vector<long long> b(n + 1);
  a[0] = -2e9;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) {
    b[i] = min(min(b[i - 1] + 20,
                   50 + b[lower_bound((a).begin(), (a).end(), a[i] - 90) -
                          a.begin() - 1]),
               120 + b[lower_bound((a).begin(), (a).end(), a[i] - 1440) -
                       a.begin() - 1]);
    cout << b[i] - b[i - 1] << endl;
  }
  return 0;
}
