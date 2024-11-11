#include <bits/stdc++.h>
using namespace std;
const long long INF = 1LL << 60;
long long n, m, k, x, y, z;
int mod = 1e9 + 7;
long long add(long long a, long long b) {
  if (a + b >= mod) return a + b - mod;
  return a + b;
}
long long sub(long long a, long long b) {
  if (a < b) return a - b + mod;
  return a - b;
}
long long mul(long long a, long long b) { return 1LL * a * b % mod; }
int power(int a, int b) {
  if (b < 0) return 0;
  int re = 1;
  while (b) {
    if (b & 1) {
      re = mul(re, a);
    }
    a = mul(a, a);
    b >>= 1;
  }
  return re;
}
bool sortbysec(const pair<long long, long long> &a,
               const pair<long long, long long> &b) {
  return (a.second < b.second);
}
bool sortbyfi(const pair<long long, pair<long long, long long>> &a,
              const pair<long long, pair<long long, long long>> &b) {
  return (a.first > b.first);
}
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
    pq;
long long bs(vector<long long> v, long long x) {
  long long hi = v.size() - 1, lo = 0;
  while (hi >= lo) {
    long long mid = lo + (hi - lo) / 2;
    if (v[mid] == x)
      return 1;
    else if (v[mid] < x)
      lo = mid + 1;
    else
      hi = mid - 1;
  }
  return 0;
}
bool paired(char a, char b) {
  if (a == '[' and b == ']') return true;
  if (a == '{' and b == '}') return true;
  if (a == '(' and b == ')') return true;
  if (a == '<' and b == '>') return true;
  return false;
}
bool cmp(string a, string b) { return (int)a.size() < (int)b.size(); }
void Birdperson() {
  cin >> n >> m;
  vector<vector<std::pair<long long, long long>>> vdr(200001);
  vector<vector<std::pair<long long, long long>>> vdl(200001);
  vector<long long> vr[100001];
  vector<long long> vc[100001];
  map<std::pair<long long, long long>, long long> mp;
  for (int i = 0; i < (m); ++i) {
    cin >> x >> y;
    x--;
    y--;
    mp[{x, y}] = 0;
    vdr[abs(x - y)].push_back({x, y});
    vdl[x + y].push_back({x, y});
    vr[x].push_back(y);
    vc[y].push_back(x);
  }
  for (int i = 0; i < (2 * n + 1); ++i) {
    sort(vdr[i].begin(), vdr[i].end());
    sort(vdl[i].begin(), vdl[i].end());
    if (i < 100001) {
      sort(vr[i].begin(), vr[i].end());
      sort(vc[i].begin(), vc[i].end());
    }
  }
  for (int i = 0; i < (2 * n + 1); ++i) {
    for (long long j = 0; j < vdr[i].size() and vdr[i].size() != 1; j++) {
      x = vdr[i][j].first;
      y = vdr[i][j].second;
      if (j == 0 or j == vdr[i].size() - 1) {
        mp[{x, y}]++;
      } else {
        mp[{x, y}] += 2;
      }
    }
    for (long long j = 0; j < vdl[i].size() and vdl[i].size() != 1; j++) {
      x = vdl[i][j].first;
      y = vdl[i][j].second;
      if (j == 0 or j == vdl[i].size() - 1) {
        mp[{x, y}]++;
      } else {
        mp[{x, y}] += 2;
      }
    }
    if (i < 100001) {
      for (long long j = 0; j < vc[i].size() and vc[i].size() != 1; j++) {
        x = vc[i][j];
        y = i;
        if (j == 0 or j == vc[i].size() - 1) {
          mp[{x, y}]++;
        } else {
          mp[{x, y}] += 2;
        }
      }
      for (long long j = 0; j < vr[i].size() and vr[i].size() != 1; j++) {
        y = vr[i][j];
        x = i;
        if (j == 0 or j == vr[i].size() - 1) {
          mp[{x, y}]++;
        } else {
          mp[{x, y}] += 2;
        }
      }
    }
  }
  long long ans[9];
  memset(ans, 0, sizeof(ans));
  for (auto x : mp) {
    ans[x.second]++;
  }
  for (auto &a : ans) cout << a << " ";
  cout << "\n";
}
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  long long cnt = 1;
  while (cnt <= t) {
    Birdperson();
    cnt++;
  }
  return 0;
}
