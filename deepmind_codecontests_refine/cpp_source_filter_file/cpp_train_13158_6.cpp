#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const double pi = acos(-1.0);
const double eps = 1e-9;
const int MAX_SIZE = 50;
const int dX[] = {-1, 1, 0, 0, -1, 1, -1, 1};
const int dY[] = {0, 0, -1, 1, 1, -1, -1, 1};
template <class S, class T>
ostream& operator<<(ostream& o, const pair<S, T>& a) {
  o << a.first << " " << a.second << " ";
  return o;
}
template <class S, class T>
ostream& operator<<(ostream& o, const map<S, T>& a) {
  for (auto& it : (a)) o << (it);
  return o;
}
template <class S>
ostream& operator<<(ostream& o, const vector<S>& a) {
  for (auto& it : (a)) o << (it) << " ";
  o << "\n";
  return o;
}
template <class S>
ostream& operator<<(ostream& o, const vector<vector<S> >& a) {
  for (auto& it : (a)) o << (it);
  return o;
}
template <class S>
ostream& operator<<(ostream& o, const set<S>& a) {
  for (auto& it : (a)) o << (it) << " ";
  o << "\n";
  return o;
}
const long long MAX = 2e5 + 10;
int sum[MAX];
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int i, n, k, x, ansa, ansb, maxb, a, b;
  long long max_sum = 0, max_suf_sum = 0;
  cin >> n >> k;
  for (i = (0); (((1) > 0) - ((1) < 0)) * i < (((1) > 0) - ((1) < 0)) * (n);
       i += (1)) {
    cin >> x;
    sum[i + 1] = sum[i] + x;
  }
  for (a = n - 2 * k + 1; a > 0; a--) {
    b = a + k;
    if (sum[b + k - 1] - sum[b - 1] >= max_suf_sum) {
      maxb = b;
      max_suf_sum = sum[b + k - 1] - sum[b - 1];
    }
    if (sum[a + k - 1] - sum[a - 1] + max_suf_sum >= max_sum) {
      max_sum = sum[a + k - 1] - sum[a - 1] + max_suf_sum;
      ansa = a;
      ansb = maxb;
    }
  }
  cout << ansa << " " << ansb << "\n";
  return 0;
}
