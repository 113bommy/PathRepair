#include <bits/stdc++.h>
using namespace std;
int main() {
  int val[26];
  for (int i = 0; i < 26; i++) cin >> val[i];
  string s;
  cin >> s;
  map<long long, int> maa;
  long long sum = 0;
  long long ans = 0;
  for (int i = 0; i < 26; i++) {
    maa.clear();
    sum = 0;
    for (int j = 0; j < s.size(); j++) {
      if (j && s[j - 1] - 'a' == i) {
        maa[sum]++;
      }
      if (s[j] - 'a' == i) {
        ans += maa[sum];
      }
      sum += val[s[j] - 'a'];
    }
  }
  cout << ans << endl;
}
