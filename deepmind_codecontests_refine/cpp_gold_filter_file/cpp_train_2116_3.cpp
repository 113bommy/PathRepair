#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int letters[m][27];
  string name;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < 27; j++) letters[i][j] = 0;
  }
  long long int ans = 1;
  while (n--) {
    cin >> name;
    for (int i = 0; i < m; i++) {
      int val = letters[i][name[i] - 'A'];
      if (val == 0) {
        letters[i][name[i] - 'A']++;
        letters[i][26]++;
      }
    }
  }
  for (int i = 0; i < m; i++) {
    ans = (ans * letters[i][26]) % 1000000007;
  }
  cout << ans << endl;
  return 0;
}
