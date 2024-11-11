#include <bits/stdc++.h>
using namespace std;
template <class S, class T>
pair<S, T> operator+(const pair<S, T> &s, const pair<S, T> &t) {
  return pair<S, T>(s.first + t.first, s.second + t.second);
}
template <class S, class T>
pair<S, T> operator-(const pair<S, T> &s, const pair<S, T> &t) {
  return pair<S, T>(s.first - t.first, s.second - t.second);
}
template <class S, class T>
ostream &operator<<(ostream &os, pair<S, T> p) {
  os << "(" << p.first << ", " << p.second << ")";
  return os;
}
template <class T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
const long long inf = 1000000001;
const long long INF = (long long)1e18 + 1;
const long long MOD = 1000003;
const double pi = 3.14159265358979323846;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
int dx2[8] = {1, 1, 0, -1, -1, -1, 0, 1}, dy2[8] = {0, 1, 1, 1, 0, -1, -1, -1};
vector<int> a;
vector<int> pos;
vector<pair<int, int> > ans;
int n;
void my_swap(int i, int j) {
  if (i == j) return;
  assert(abs(i - j) * 2 >= n);
  int x = a[i], y = a[j];
  ans.push_back(pair<int, int>(i, j));
  swap(a[i], a[j]);
  pos[x] = j;
  pos[y] = i;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  ;
  cin >> n;
  a.resize(n);
  pos.resize(n);
  for (int i = 0; i < (n); i++) {
    cin >> a[i];
    a[i]--;
    pos[a[i]] = i;
  }
  int l = n / 2 - 1, r = n / 2;
  for (int q = 0; q < (n); q++) {
    if (q % 2 == 0) {
      int i = pos[l];
      if (i >= n / 2) {
        my_swap(0, i);
      }
      i = pos[l];
      my_swap(i, n - 1);
      my_swap(n - 1, l);
      l--;
    } else {
      int i = pos[r];
      if (i < n / 2) {
        my_swap(i, n - 1);
      }
      i = pos[r];
      my_swap(i, 0);
      my_swap(0, r);
      r++;
    }
  }
  cout << ans.size() << '\n';
  for (int i = 0; i < (ans.size()); i++) {
    cout << ans[i].first + 1 << " " << ans[i].second + 1 << '\n';
  }
}
