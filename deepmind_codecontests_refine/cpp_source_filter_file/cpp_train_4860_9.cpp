#include <bits/stdc++.h>
using namespace std;
map<long long, long long> a;
long long ans;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long n;
  cin >> n;
  for (long long i = 0; i < n; i++) {
    string s;
    cin >> s;
    long long cnt = 0;
    long long mini = 0;
    for (long long j = 0; j < s.size(); j++) {
      if (s[j] == '(')
        cnt++;
      else
        cnt--;
      mini = min(mini, cnt);
    }
    if (cnt < 0 && cnt > mini) continue;
    if (cnt > 0 && mini < 0) continue;
    a[cnt]++;
  }
  for (auto i : a) {
    if (i.first < 0) continue;
    ans += i.second * a[-i.first];
  }
  cout << ans;
  return 0;
}
