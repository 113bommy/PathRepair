#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using db = double;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<db, db>;
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vd = vector<db>;
using vs = vector<str>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vpd = vector<pd>;
template <class T>
using V = vector<T>;
template <class T, size_t SZ>
using AR = array<T, SZ>;
template <class T>
using PR = pair<T, T>;
const int MOD = 1e9 + 7;
const int MX = 2e5 + 5;
const ll INF = 1e18;
const ld PI = acos((ld)-1);
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;
void solve() {
  int N, K, C;
  cin >> N >> K >> C;
  vi arr;
  arr.push_back(0);
  for (int i = (0); i < (C); ++i) {
    int input;
    cin >> input;
    arr.push_back(input);
  }
  int counter = arr.size() - 1;
  arr.push_back(N + 1);
  for (int i = (0); i < (arr.size() - 1); ++i) {
    int start = arr[i];
    int end = arr[i + 1];
    if (start == end) continue;
    counter += (end - start - 1) / K;
  }
  cout << counter << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
