#include <bits/stdc++.h>
double EPS = 1e-9;
constexpr long long MOD = 1e9 + 9;
using namespace std;
map<pair<long long, long long>, long long> mp;
set<long long> wws;
set<long long> hs;
long long gcd(long long a, long long b) {
  long long t;
  while (b) {
    t = a;
    a = b;
    b = t % a;
  }
  return a;
}
bool eq(long long a00, long long a11, long long a01, long long a10) {
  for (int i = 0; i < 3; i++) {
    long long x = rand();
    if (x == 0) {
      i--;
      continue;
    }
    if (a00 % x * a11 % x != a01 % x * a10 % x) return 0;
  }
  return 1;
}
void generate_divs(long long x, vector<long long>& res) {
  long long i;
  for (i = 1; i * i < x; i++) {
    if (x % i == 0) {
      res.push_back(i);
      res.push_back(x / i);
    }
  }
  if (i * i == x) {
    res.push_back(i);
  }
}
long long g_row[200001];
long long g_col[200001];
long long first_row[200001];
long long first_col[200001];
bool can1(long long a) {
  int i = 0;
  for (auto el : hs) {
    if (g_col[i] % (first_col[i] / a) != 0) return 0;
    i++;
  }
  return 1;
}
bool can2(long long a) {
  int i = 0;
  for (auto el : wws) {
    if (g_row[i] % (first_row[i] / a) != 0) return 0;
    i++;
  }
  return 1;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  long long h, w, c;
  for (int i = 0; i < n; i++) {
    cin >> w >> h >> c;
    wws.insert(w);
    hs.insert(h);
    mp[{w, h}] = c;
  }
  if ((long long)wws.size() * hs.size() != n) {
    cout << 0;
    return 0;
  }
  long long arr[wws.size()][hs.size()];
  int wid, hei;
  wid = wws.size(), hei = hs.size();
  int i, j;
  i = j = 0;
  for (auto ww : wws) {
    j = 0;
    for (auto hh : hs) {
      arr[i][j] = mp[{ww, hh}];
      j++;
    }
    i++;
  }
  for (int i = 0; i < wid; i++) {
    for (int j = 0; j < hei; j++) {
      if (!eq(arr[0][0], arr[i][j], arr[0][j], arr[i][0])) {
        cout << 0;
        return 0;
      }
    }
  }
  for (int i = 0; i < wid; i++) {
    for (int j = 0; j < hei; j++) {
      g_row[i] = gcd(g_row[i], arr[i][j]);
    }
  }
  for (int j = 0; j < hei; j++) {
    for (int i = 0; i < wid; i++) {
      g_col[j] = gcd(g_col[j], arr[i][j]);
    }
  }
  for (int i = 0; i < hei; i++) {
    first_col[i] = arr[0][i];
  }
  for (int i = 0; i < wid; i++) {
    first_row[i] = arr[i][0];
  }
  bool rows = (wws.size() > hs.size());
  vector<long long> divs;
  divs.reserve(10000);
  generate_divs((rows ? g_row[0] : g_col[0]), divs);
  long long res = 0;
  for (auto el : divs) {
    if ((rows ? can1(el) : can2(el))) res++;
  }
  cout << res;
  return 0;
}
