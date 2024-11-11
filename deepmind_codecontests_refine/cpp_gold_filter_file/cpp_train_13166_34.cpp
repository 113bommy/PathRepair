#include <bits/stdc++.h>
using namespace std;
map<long long, long long> M[30];
int values[100010];
char str[100010];
int N;
int counts[30];
long long sums[30];
inline void ReadInput(void) {
  for (int i = 0; i < 26; i++) scanf("%d", &values[i]);
  scanf("%s", str);
}
long long ans = 0;
inline void solve(void) {
  N = strlen(str);
  for (int i = 1; i <= N; i++) {
    int pos = str[i - 1] - 'a';
    ans += (M[pos][0 - sums[pos]]);
    for (int j = 0; j < 26; j++) {
      if (counts[j] > 0) {
        sums[j] += values[pos];
      }
    }
    M[pos][0 - sums[pos]]++;
    counts[pos]++;
  }
  cout << ans;
}
inline void Refresh(void) {}
int main() {
  ReadInput();
  solve();
  return 0;
}
