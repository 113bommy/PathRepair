#include <bits/stdc++.h>
using namespace std;
long long cnt[2][2];
int n;
string s1, s2;
int main() {
  cin >> n;
  cin >> s1 >> s2;
  for (int i = 0; i < n; i++) {
    cnt[s1[i] - '0'][s2[i] - '0']++;
  }
  cout << cnt[0][0] * cnt[1][0] + cnt[0][0] * cnt[1][1] + cnt[0][1] * cnt[1][0]
       << endl;
  return 0;
}
