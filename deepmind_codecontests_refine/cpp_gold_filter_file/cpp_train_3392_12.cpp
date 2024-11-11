#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:10240000")
using namespace std;
long long a[123456];
int cnt[45];
int lowerThan[45];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    long long b = a[i];
    int c = 0;
    while (!(b & 1)) {
      b >>= 1;
      ++c;
    }
    if (b == 1) cnt[c]++;
  }
  for (int j = 0; j < 44; ++j) {
    long long curCur = 1ll << j;
    for (int i = 0; i < n; ++i)
      if (curCur > a[i]) ++lowerThan[j];
  }
  vector<int> answer;
  for (int i = 1; i <= n; ++i) {
    int curSet = 0;
    int rest = n;
    int cur = i;
    if (cnt[0] < i) break;
    for (int j = 0; j <= 42; ++j) {
      int r = min(cnt[j], cur);
      int nextNumberOfSet = min(lowerThan[j] - curSet, cur - r);
      curSet += r;
      curSet += nextNumberOfSet;
      rest -= nextNumberOfSet;
      rest -= r;
      cur = r;
    }
    if (rest == 0) answer.push_back(i);
  }
  if (answer.size() == 0)
    cout << -1;
  else
    for (int i = 0; i < answer.size(); ++i) cout << answer[i] << " ";
  cout << endl;
}
