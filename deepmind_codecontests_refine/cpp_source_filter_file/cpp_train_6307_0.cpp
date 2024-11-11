#include <bits/stdc++.h>
using namespace std;
template <typename T, typename S>
inline bool REMIN(T &a, const S &b) {
  return a > b ? a = b, 1 : 0;
}
template <typename T, typename S>
inline bool REMAX(T &a, const S &b) {
  return a < b ? a = b, 1 : 0;
}
int toint(const string &s) {
  stringstream ss;
  ss << s;
  int x;
  ss >> x;
  return x;
}
string tostring(int number) {
  stringstream ss;
  ss << number;
  return ss.str();
}
int bit(long long x, int pos) { return ((1ll << pos) & x) ? 1 : 0; }
const int INF = 1e9;
const int NMAX = 7e3 + 5;
const long long MOD = 1000000007;
const long double PI = 2 * acos(0);
long long power(long long base, long long exp, long long c = MOD) {
  if (!exp) return 1;
  long long r = power(base, exp / 2, c);
  r = (r * r) % c;
  if (exp & 1) r = (r * base) % c;
  return r;
}
int T, N, M;
int a, b, c;
string s1, s2;
vector<int> moves[2];
queue<pair<int, int> > q;
int deg[NMAX][2];
int win[NMAX][2];
void nope(int dec = 0) {
  if (!dec) cout << "NO";
  exit(0);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  for (int(who) = int(0); (who) <= int(1); ++(who)) {
    cin >> a;
    for (int(i) = int(1); (i) <= int(a); ++(i)) {
      cin >> b;
      b %= N;
      moves[who].push_back(b);
    }
  }
  for (int(who) = int(0); (who) <= int(1); ++(who)) {
    for (int(i) = int(1); (i) <= int(N - 1); ++(i)) {
      deg[i][who] = ((int)(moves[who].size()));
    }
  }
  q.push({0, 0});
  q.push({0, 1});
  while (!q.empty()) {
    auto pa = q.front();
    q.pop();
    int curr = pa.first, who = pa.second;
    for (int jump : moves[1 - who]) {
      int to = (curr - jump + N) % N;
      if (win[to][1 - who]) continue;
      if (win[curr][who]) {
        deg[to][1 - who]--;
        if (!deg[to][1 - who]) q.push({to, 1 - who});
      } else {
        win[to][1 - who] = 1;
        q.push({to, 1 - who});
      }
    }
  }
  for (int(who) = int(0); (who) <= int(1); ++(who)) {
    for (int(i) = int(1); (i) <= int(N - 1); ++(i)) {
      if (win[i][who])
        cout << "Win ";
      else if (deg[i][0])
        cout << "Loop ";
      else
        cout << "Lose ";
    }
    cout << "\n";
  }
  return 0;
}
