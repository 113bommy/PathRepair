#include <bits/stdc++.h>
using namespace std;
template <typename T>
istream &operator>>(istream &in, vector<T> &v) {
  for (auto &i : v) cin >> i;
  return in;
}
template <typename T>
istream &operator>>(istream &in, pair<T, T> &p) {
  cin >> p.f >> p.s;
  return in;
}
template <typename T>
ostream &operator<<(ostream &out, vector<T> &v) {
  for (auto &i : v) cout << i << " ";
  return out;
}
template <typename T>
ostream &operator<<(ostream &out, pair<T, T> &p) {
  cout << p.f << " " << p.s << " ";
  return out;
}
template <typename T>
istream &operator>>(istream &in, vector<pair<T, T>> &v) {
  for (auto &i : v) cin >> i.f >> i.s;
  return in;
}
template <typename T>
ostream &operator<<(ostream &out, vector<pair<T, T>> &v) {
  for (auto &i : v) cout << i.f << " " << i.s << "\n";
  return out;
}
void solve() {
  long long int t;
  cin >> t;
  for (long long int _ = 1; _ <= t; _++) {
    long long int k;
    cin >> k;
    string s;
    cin >> s;
    vector<long long int> arr(10, 0);
    for (auto &ch : s) {
      arr[ch - '0']++;
    }
    long long int ans[] = {1, 4, 6, 8, 9};
    bool flag = 0;
    for (auto i : ans) {
      if (arr[i]) {
        cout << "1\n" << i << "\n";
        flag = 1;
        break;
      }
    }
    if (flag) continue;
    if (arr[2] > 1) {
      cout << "2"
           << "\n"
           << 22 << "\n";
      continue;
    }
    if (arr[2] == 1 and s[0] != '2') {
      cout << 2 << "\n";
      cout << s[0] << 2 << "\n";
      continue;
    }
    if (arr[2]) {
      if (arr[5] or arr[7]) {
        cout << "2"
             << "\n";
        cout << 2 << ((arr[5] ? 5 : 7)) << "\n";
      } else {
        cout << "2\n33"
             << "\n";
      }
      continue;
    }
    if (arr[3] > 1 or arr[5] > 1 or arr[7] > 1) {
      cout << 2 << "\n";
      cout << (arr[3] > 1 ? 33 : arr[5] > 1 ? 55 : 77) << "\n";
      continue;
    }
    cout << 2 << "\n";
    cout << (s[0] == '3' ? 35 : s[0] == '5' ? 57 : 75) << "\n";
  }
}
int main() {
  solve();
  return 0;
}
