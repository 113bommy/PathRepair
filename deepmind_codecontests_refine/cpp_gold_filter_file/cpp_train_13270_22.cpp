#include <bits/stdc++.h>
using namespace std;
struct Counter {
  static int k;
  Counter() { k++; }
  ~Counter() { k--; }
};
int Counter::k = 0;
template <typename T>
void pr(const string& name, T t) {
  cout << name << " = " << t << endl;
}
template <typename T, typename... Types>
void pr(const string& names, T t, Types... rest) {
  auto comma_pos = names.find(',');
  cout << names.substr(0, comma_pos) << " = " << t << ", ";
  auto next_name_pos = names.find_first_not_of(" \t\n", comma_pos + 1);
  pr(string(names, next_name_pos), rest...);
}
void mod(long long& a, long long b) {
  a %= b;
  if (a < 0) a += b;
}
const long long MOD = 1000000007;
int Cap[1005][1005], D[555], H, W, N, K, M, F, Seen[1005], From[1005];
queue<int> Q;
string B;
vector<int> E[1005];
vector<pair<int, int>> MaleDist[555], FemaleDist[555], Males, Females;
void bfs(int st, vector<pair<int, int>>& v) {
  for (int i = (0); i <= (N - 1); i++) D[i] = 999;
  D[st] = 0;
  Q.push(st);
  while (!Q.empty()) {
    int n = Q.front();
    Q.pop();
    if (n >= W && D[n - W] > D[n] + 1 && B[n - W] == '.') {
      D[n - W] = D[n] + 1;
      Q.push(n - W);
    }
    if (n + W < N && D[n + W] > D[n] + 1 && B[n + W] == '.') {
      D[n + W] = D[n] + 1;
      Q.push(n + W);
    }
    if (n % W < W - 1 && D[n + 1] > D[n] + 1 && B[n + 1] == '.') {
      D[n + 1] = D[n] + 1;
      Q.push(n + 1);
    }
    if (n % W > 0 && D[n - 1] > D[n] + 1 && B[n - 1] == '.') {
      D[n - 1] = D[n] + 1;
      Q.push(n - 1);
    }
  }
  for (int i = (0); i <= (N - 1); i++)
    if (D[i] < 999) v.push_back({D[i], i});
  sort(v.begin(), v.end(), greater<pair<int, int>>());
}
bool ok(long long limit) {
  int s = 2 * N + 2 * K;
  int t = 2 * N + 2 * K + 1;
  for (int i = (0); i <= (t); i++) E[i].clear();
  for (int i = (2 * N); i <= (2 * N + K - 1); i++)
    E[s].push_back(i), E[i].push_back(s), Cap[s][i] = 1, Cap[i][s] = 0;
  for (int i = (0); i <= (N - 1); i++)
    E[i].push_back(i + N), E[i + N].push_back(i), Cap[i][i + N] = 1,
                                                             Cap[i + N][i] = 0;
  for (int i = (2 * N + K); i <= (2 * N + 2 * K - 1); i++)
    E[i].push_back(t), E[t].push_back(i), Cap[i][t] = 1, Cap[t][i] = 0;
  for (int i = (0); i <= (K - 1); i++) {
    long long t = Males[i].second;
    for (int p = (((int)MaleDist[i].size()) - 1); p >= (0); p--)
      if (t * MaleDist[i][p].first <= limit) {
        int n1 = 2 * N + i;
        int n2 = MaleDist[i][p].second;
        Cap[n1][n2] = 1, Cap[n2][n1] = 0;
        E[n1].push_back(n2), E[n2].push_back(n1);
      }
  }
  for (int i = (0); i <= (K - 1); i++) {
    long long t = Females[i].second;
    for (int p = (((int)FemaleDist[i].size()) - 1); p >= (0); p--)
      if (t * FemaleDist[i][p].first <= limit) {
        int n1 = N + FemaleDist[i][p].second;
        int n2 = 2 * N + K + i;
        Cap[n1][n2] = 1, Cap[n2][n1] = 0;
        E[n1].push_back(n2), E[n2].push_back(n1);
      }
  }
  for (int i = (0); i <= (t); i++) Seen[i] = -1;
  int flow = 0;
  while (true) {
    Seen[s] = flow;
    Q.push(s);
    while (!Q.empty()) {
      int n = Q.front();
      Q.pop();
      if (n == t) {
        while (!Q.empty()) Q.pop();
        break;
      }
      for (int v : E[n])
        if (Cap[n][v] && Seen[v] < flow) {
          From[v] = n;
          Seen[v] = flow;
          Q.push(v);
        }
    }
    if (Seen[t] < flow) break;
    int n = t;
    while (n != s) {
      Cap[From[n]][n]--, Cap[n][From[n]]++;
      n = From[n];
    }
    flow++;
  }
  return flow == K;
}
int main() {
  cin >> H >> W >> M >> F;
  N = H * W;
  for (int i = (0); i <= (H - 1); i++) {
    string s;
    cin >> s;
    B += s;
  }
  if (M != F + 1 && M != F - 1) {
    cout << "-1";
    return 0;
  }
  int i, j, t;
  cin >> i >> j >> t;
  i--, j--;
  if (M < F)
    Males.push_back({i * W + j, t});
  else
    Females.push_back({i * W + j, t});
  K = min(M, F) + 1;
  for (int x = (1); x <= (M); x++) {
    int i, j, t;
    cin >> i >> j >> t;
    i--, j--;
    Males.push_back({i * W + j, t});
  }
  for (int x = (1); x <= (F); x++) {
    int i, j, t;
    cin >> i >> j >> t;
    i--, j--;
    Females.push_back({i * W + j, t});
  }
  for (int i = (0); i <= (K - 1); i++) bfs(Males[i].first, MaleDist[i]);
  for (int i = (0); i <= (K - 1); i++) bfs(Females[i].first, FemaleDist[i]);
  long long a = 0, b = 242000000000;
  while (b - a > 1) {
    long long p = (a + b) / 2;
    if (ok(p))
      b = p;
    else
      a = p;
  }
  if (ok(a))
    cout << a;
  else if (ok(b))
    cout << b;
  else
    cout << "-1";
}
