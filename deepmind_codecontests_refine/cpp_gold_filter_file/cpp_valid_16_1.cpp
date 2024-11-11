#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(NULL);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n, cnt = 0;
    cin >> n;
    char str[41], str2[41];
    cin >> str;
    strcpy(str2, str);
    for (long long i = 0; i < n; i++) {
      for (long long j = i + 1; j < n; j++) {
        if (str2[j] < str2[i]) {
          char temp;
          temp = str2[i];
          str2[i] = str2[j];
          str2[j] = temp;
        }
      }
    }
    for (long long i = 0; i < n; i++) {
      if (str[i] != str2[i]) cnt++;
    }
    cout << cnt << "\n";
  }
  return 0;
}
