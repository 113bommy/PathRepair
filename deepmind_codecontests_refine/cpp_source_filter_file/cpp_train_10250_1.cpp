#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t = 1;
  while (t--) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    long long freq[26] = {0};
    for (int i = 0; i < s.size(); i++) freq[s[i] - 'A']++;
    long long ans = 0;
    sort(freq, freq + 26, greater<long long>());
    for (int i = 0; i < 26; i++) {
      if (k == 0) break;
      if (freq[i] < k) {
        ans += freq[i] * freq[i];
        k -= freq[i];
      } else {
        ans += k * k;
        break;
      }
    }
    cout << ans << endl;
  }
}
