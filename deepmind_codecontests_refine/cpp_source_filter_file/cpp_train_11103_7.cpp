#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n;
  cin >> n;
  string s;
  cin >> s;
  long long int mv = n - 1;
  for (long long int i = 0; i < n - 1; i++) {
    if (s[i] == 'U' && s[i + 1] == 'R') {
      mv--;
      s[i + 1] = 'D';
    }
    if (s[i] == 'R' && s[i - 1] == 'u') {
      mv--;
      s[i + 1] = 'D';
    }
  }
  cout << mv;
}
