#include <bits/stdc++.h>
using namespace std;
template <typename A>
ostream &operator<<(ostream &cout, vector<A> const &v) {
  for (long long i = 0; i < v.size(); i++) cout << v[i] << " ";
  cout << "\n";
}
template <typename A, typename B>
ostream &operator<<(ostream &cout, map<A, B> const &v) {
  for (auto x : v) cout << x.first << ": " << x.second << "\n";
}
template <typename A>
ostream &operator<<(ostream &cout, vector<array<A, 2>> const &v) {
  for (long long i = 0; i < v.size(); i++)
    cout << v[i][0] << " " << v[i][1] << "\n";
}
int32_t main() {
  long long n;
  cin >> n;
  if (n % 2)
    cout << "black";
  else
    cout << "white\n1 2";
}
