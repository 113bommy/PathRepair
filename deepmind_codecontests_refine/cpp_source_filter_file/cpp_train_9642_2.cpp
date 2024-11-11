#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int tt = 1;
  while (tt--) {
    long long int n;
    cin >> n;
    string s;
    cin >> s;
    long long int f_s = 0;
    long long int s_f = 0;
    for (long long int i = 1; i <= n - 1; i++) {
      if (s[i] == 'F' and s[i - 1] == 'S') f_s++;
      if (s[i] == 'S' and s[i - 1] == 'F') s_f++;
    }
    if (s_f > f_s)
      cout << "YES";
    else
      cout << "NO";
  }
  return 0;
}
