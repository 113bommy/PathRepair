#include <bits/stdc++.h>
const int mod = 1000000007;
const int inf = 1000000009;
const long long INF = 1000000000000000009;
const long long big = 1000000000000000;
const long double eps = 0.0000000001;
using namespace std;
struct punkt {
  int x1, y1, x2, y2;
};
punkt T[100005];
map<int, int> K;
int D[100005], O[100005];
vector<int> W, S[600005];
int suma = 1;
bool cmp(int a, int b) { return T[a].y1 > T[b].y1; }
int Y, d, o;
queue<int> Q;
void ustaw(int a, int b, int lo, int hi, int u) {
  if (b <= a) return;
  if (a == lo && b == hi) {
    while (!S[u].empty() && T[S[u].back()].y1 <= Y) {
      int x = S[u].back();
      S[u].pop_back();
      if (D[x] != inf) continue;
      D[x] = d + 1;
      O[x] = o;
      Q.push(x);
    }
    return;
  }
  int mid = (lo + hi) / 2;
  ustaw(a, min(b, mid), lo, mid, 2 * u);
  ustaw(max(a, mid), b, mid, hi, 2 * u + 1);
}
vector<int> A;
int main() {
  ios::sync_with_stdio(false);
  cin.tie();
  cout.tie();
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    T[i] = {a, b, c, d};
    W.push_back(a), W.push_back(c);
  }
  W.push_back(0);
  sort(W.begin(), W.end());
  int numer = 0;
  int last = -1;
  for (auto v : W) {
    if (last != v) {
      numer++;
      K[v] = numer;
    }
    last = v;
  }
  while (suma < numer) suma *= 2;
  suma *= 2;
  suma--;
  for (int i = 1; i <= n; i++) S[K[T[i].x1] + suma / 2].push_back(i);
  for (int i = suma / 2 + 1; i <= suma; i++)
    sort(S[i].begin(), S[i].end(), cmp);
  for (int i = suma / 2; i >= 1; i--) {
    int s1 = S[2 * i].size() - 1, s2 = S[2 * i + 1].size() - 1;
    int x = 0, y = 0;
    while (x <= s1 || y <= s2) {
      if (x > s1) {
        S[i].push_back(S[2 * i + 1][y]);
        y++;
      } else if (y > s2) {
        S[i].push_back(S[2 * i][x]);
        x++;
      } else {
        if (T[S[2 * i][x]].y1 > T[S[2 * i + 1][y]].y1) {
          S[i].push_back(S[2 * i][x]);
          x++;
        } else {
          S[i].push_back(S[2 * i + 1][y]);
          y++;
        }
      }
    }
  }
  T[0] = {0, 0, 0, 0};
  for (int i = 1; i <= n; i++) D[i] = inf;
  Q.push(0);
  while (!Q.empty()) {
    int u = Q.front();
    Q.pop();
    d = D[u];
    Y = T[u].y2;
    o = u;
    ustaw(1, K[T[u].x2] + 1, 1, suma / 2 + 2, 1);
  }
  if (D[n] == inf) {
    cout << -1;
    return 0;
  }
  cout << D[n] << "\n";
  int last2 = n;
  while (last2 != 0) {
    A.push_back(last2);
    last2 = O[last2];
  }
  reverse(A.begin(), A.end());
  for (auto v : A) cout << v << " ";
  return 0;
}
