#include <bits/stdc++.h>
using namespace std;
int A[1000005];
int Begin[505], End[505];
int Inv[2][1000005];
int Who[505][505];
int DP[505 * 505], N, M, cnt;
int Min[505][505];
pair<int, int> P[505 * 505];
vector<int> V[505], Real[505];
const int MOD = 998244353;
void precalcMin() {
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (Begin[i] > End[j]) continue;
      int res = N + 1;
      for (int k = 1; k <= N; k++)
        if (Begin[k] >= Begin[i] && Begin[k] <= End[j]) {
          res = k;
          break;
        }
      Min[i][j] = res;
    }
  }
}
void Read() {
  scanf("%d%d", &N, &M);
  for (int i = 1; i <= M; i++) {
    scanf("%d", &A[i]);
    V[A[i]].push_back(i);
  }
}
void precalcBegin() {
  for (int i = 1; i <= N; i++) Begin[i] = V[i][0], Inv[0][Begin[i]] = i;
}
void precalcEnd() {
  for (int i = 1; i <= N; i++) End[i] = V[i].back(), Inv[1][End[i]] = i;
}
void precalcReal() {
  for (int i = 1; i <= N; i++) {
    for (int j = 0; j < V[i].size(); j++) {
      int pos = V[i][j];
      if (A[pos - 1] != i || A[pos + 1] != i) Real[i].push_back(pos);
    }
  }
}
inline bool cmp(pair<int, int> a, pair<int, int> b) {
  return End[a.second] - Begin[a.first] < End[b.second] - Begin[b.first];
}
bool check(int left, int right) {
  for (int i = 1; i <= N; i++) {
    if (!((Begin[i] >= left && End[i] <= right) ||
          (Begin[i] > right || End[i] < left) ||
          (Begin[i] < left && End[i] > right)))
      return false;
  }
  return true;
}
void precalcWho() {
  for (int i = 1; i <= cnt; i++) Who[P[i].first][P[i].second] = i;
}
int norm(int x) {
  if (x >= MOD) x -= MOD;
  return x;
}
void precalcDP() {
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++) {
      if (Begin[i] > End[j]) continue;
      P[++cnt] = make_pair(i, j);
    }
  sort(P + 1, P + cnt + 1, cmp);
  precalcWho();
  DP[0] = 0;
  for (int i = 1; i <= cnt; i++) {
    int left = Begin[P[i].first], right = End[P[i].second];
    bool ok = check(left, right);
    if (!ok) {
      DP[i] = 0;
      continue;
    }
    DP[i] = 1;
    int who = Min[P[i].first][P[i].second], first = -1, valLeft = 0,
        valRight = 0, last = -1;
    for (int j = 0; j < Real[who].size(); j++) {
      int pos = Real[who][j];
      if (pos < left || pos > right) continue;
      last = pos;
      if (first == -1) {
        int val = 1;
        if (left == pos) {
          valLeft = 1;
          first = 1;
          continue;
        }
        valLeft = DP[Who[Inv[0][left]][Inv[1][pos - 1]]];
        for (int k = 1; k <= N; k++) {
          if (Begin[k] >= left && End[k] < pos) {
            int left1 = Inv[0][left], right1 = Inv[1][Begin[k] - 1],
                left2 = Inv[0][Begin[k]], right2 = Inv[1][pos - 1];
            int aux1 = left > (Begin[k] - 1) ? 1 : DP[Who[left1][right1]];
            valLeft =
                norm(valLeft + ((1LL * aux1 * DP[Who[left2][right2]]) % MOD));
          }
        }
        first = 1;
        continue;
      }
      if (Real[who][j - 1] + 1 != Real[who][j] &&
          A[Real[who][j - 1] + 1] != who)
        DP[i] =
            (1LL * DP[i] *
             DP[Who[Inv[0][Real[who][j - 1] + 1]][Inv[1][Real[who][j] - 1]]]) %
            MOD;
    }
    if (last == right)
      valRight = 1;
    else {
      for (int k = 1; k <= N; k++) {
        if (Begin[k] > last && End[k] <= right) {
          int left1 = Inv[0][last + 1], right1 = Inv[1][End[k]],
              left2 = Inv[0][End[k] + 1], right2 = Inv[1][right];
          int aux2 = (End[k] + 1) > right ? 1 : DP[Who[left2][right2]];
          valRight =
              norm(valRight + ((1LL * DP[Who[left1][right1]] * aux2) % MOD));
        }
      }
      valRight = norm(valRight + DP[Who[Inv[0][last + 1]][Inv[1][right]]]);
    }
    DP[i] = (1LL * DP[i] * valLeft) % MOD;
    DP[i] = (1LL * DP[i] * valRight) % MOD;
  }
  printf("%d\n", DP[cnt]);
}
int main() {
  Read();
  precalcBegin();
  precalcEnd();
  precalcMin();
  precalcReal();
  precalcDP();
  return 0;
}
