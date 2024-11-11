#include <bits/stdc++.h>
using namespace std;
const int MAXN = 23;
int num[MAXN];
int bits[1 << MAXN];
int N;
bool dp[2][1 << MAXN];
int main() {
  for (int s = 1; s < (1 << MAXN); ++s) {
    bits[s] = bits[s >> 1] + (s & 1);
  }
  while (cin >> N) {
    bool id = 0;
    for (int i = 0; i < N; ++i) {
      cin >> num[i];
    }
    dp[0][1] = 1;
    for (int i = 1; i < N; ++i) {
      id = !id;
      vector<int> mac;
      for (int j = 0; j < i; ++j)
        for (int k = 0; k <= j; ++k)
          if (num[i] == num[j] + num[k]) mac.push_back((1 << j) | (1 << k));
      for (int l = 0; l < (1 << i); ++l)
        if (dp[!id][l]) {
          dp[!id][l] = 0;
          for (int j = 0; j < mac.size(); ++j)
            if ((mac[j] & l) == mac[j]) {
              int v = l | (1 << i);
              if (bits[v] > 8) continue;
              dp[id][v] = 1;
              for (int b = 0; b < i; ++b)
                if ((1 << b) & v) dp[id][(1 << b) ^ v] = 1;
            }
        }
    }
    int ans = N + 1;
    for (int s = 0; s < (1 << N); ++s)
      if (dp[id][s] && bits[s] < ans) ans = bits[s];
    cout << (ans > N ? -1 : ans) << endl;
  }
  return 0;
}
