#include <bits/stdc++.h>
using namespace std;
string ar[] = {"1234", "1243", "1342", "1324", "1423", "1432", "2341", "2314",
               "2413", "2431", "2134", "2143", "3412", "3421", "3124", "3142",
               "3241", "3214", "4123", "4132", "4231", "4213", "4312", "4321"};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int n;
  cin >> n;
  long long int mt[205][205];
  for (long long int i = 1; i <= 2 * n; i++) {
    for (long long int j = 1; j <= 2 * n; j++) {
      if ((i + j) % 2 == 0)
        mt[i][j] = 0;
      else
        mt[i][j] = 1;
    }
  }
  vector<string> v[5];
  string s;
  for (long long int i = 1; i <= 4; i++) {
    for (long long int j = 1; j <= n; j++) {
      cin >> s;
      v[i].push_back(s);
    }
  }
  long long int ans = 1000000007;
  for (long long int i = 0; i < 24; i++) {
    vector<string> a, b, c, d, vv;
    long long int cn = 0;
    a = v[ar[i][0] - '0'];
    b = v[ar[i][1] - '0'];
    c = v[ar[i][2] - '0'];
    d = v[ar[i][3] - '0'];
    for (long long int j = 0; j < n; j++) {
      s = a[j] + b[j];
      vv.push_back(s);
    }
    for (long long int j = 0; j < n; j++) {
      s = c[j] + d[j];
      vv.push_back(s);
    }
    for (long long int j = 0; j < vv.size(); j++) {
      for (long long int k = 0; k < vv[j].size(); k++) {
        if (vv[j][k] - '0' != mt[j + 1][k + 1]) cn += 1;
      }
    }
    ans = min(ans, cn);
  }
  cout << ans << '\n';
}
