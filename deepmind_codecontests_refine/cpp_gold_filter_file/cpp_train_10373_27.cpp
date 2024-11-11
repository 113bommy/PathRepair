#include <bits/stdc++.h>
using namespace std;
int m, n;
int R[1005];
map<int, int> cnt;
long long bell[1005][1005];
void geneBell() {
  bell[0][0] = 1;
  for (int i = 1; i < m + 2; i++) {
    bell[i][0] = bell[i - 1][i - 1];
    for (int j = 1; j <= i; j++) {
      bell[i][j] = (bell[i][j - 1] + bell[i - 1][j - 1]) % 1000000007;
    }
  }
}
int main() {
  cin >> m >> n;
  geneBell();
  string tmp;
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    for (int j = 0; j < m; j++) {
      R[j] = R[j] * 10 + tmp[j] - '0';
    }
  }
  for (int i = 0; i < m; i++) {
    cnt[R[i]]++;
  }
  map<int, int>::iterator it;
  long long ans = 1;
  for (it = cnt.begin(); it != cnt.end(); ++it) {
    if ((it->second) > 0) {
      ans = (ans * bell[it->second][0]) % 1000000007;
    }
  }
  cout << ans;
  return 0;
}
