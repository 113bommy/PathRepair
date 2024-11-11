#include <bits/stdc++.h>
template <typename T>
T gcd(T a, T b) {
  if (!b) return a;
  return gcd(b, a % b);
}
template <typename T>
T lcm(T a, T b) {
  return a * b / gcd(a, b);
}
template <typename T>
void chmin(T& a, T b) {
  a = (a > b) ? b : a;
}
template <typename T>
void chmax(T& a, T b) {
  a = (a < b) ? b : a;
}
int in() {
  int x;
  scanf("%d", &x);
  return x;
}
using namespace std;
const int MAXN = 502;
int N, K;
int P[MAXN];
int dp[MAXN][MAXN][2][2];
int mark[MAXN][MAXN][2][2];
int now;
int goal;
int func(int pos, int sum, int seenG, int seenK) {
  if (sum == goal) {
    seenG = 1;
  }
  if (sum == K) {
    seenK = 1;
  }
  if (sum > K) {
    return 0;
  } else if (pos == N) {
    return seenG && seenK ? 1 : 0;
  } else {
    int& ans = dp[pos][sum][seenG][seenK];
    if (mark[pos][sum][seenG][seenK] != now) {
      mark[pos][sum][seenG][seenK] = now;
      ans = 0;
      if (func(pos + 1, sum + P[pos], seenG, seenK) == 1) {
        ans = 1;
      }
      if (ans == 0 && func(pos + 1, sum, seenG, seenK) == 1) {
        ans = 1;
      }
    }
    return ans;
  }
}
int main(void) {
  srand(time(NULL));
  cin >> N >> K;
  for (int i = 0; i < N; i++) {
    cin >> P[i];
  }
  vector<int> ans;
  for (int x = 0; (int)ans.size() < K + 1 && x < 100; x++) {
    random_shuffle(P, P + N);
    for (int i = 0; i <= K; i++) {
      if (find(ans.begin(), ans.end(), i) == ans.end()) {
        goal = i;
        now += 1;
        if (func(0, 0, 0, 0) == 1) {
          ans.push_back(i);
        }
      }
    }
  }
  cout << ans.size() << "\n";
  sort(ans.begin(), ans.end());
  for (int i = 0; i < (int)ans.size(); i++) {
    cout << ans[i] << " ";
  }
  cout << "\n";
  return 0;
}
