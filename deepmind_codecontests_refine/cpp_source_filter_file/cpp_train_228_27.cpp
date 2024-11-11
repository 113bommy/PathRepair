#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    char s[200002];
    cin.ignore();
    cin.getline(s, 200000);
    long long cnt[200002] = {0};
    cnt[n - 1] = 1;
    for (int i = 0; i < m; i++) {
      int temp;
      cin >> temp;
      if (temp > 0) cnt[temp - 1]++;
    }
    for (int i = n - 1; i > 0; i--) {
      cnt[i - 1] += cnt[i];
    }
    long long ans[26] = {0};
    for (int i = 0; i < n; i++) {
      ans[s[i] - 'a'] += cnt[i];
    }
    for (int i = 0; i < 26; i++) {
      cout << ans[i] << " ";
    }
    cout << endl;
  }
}
