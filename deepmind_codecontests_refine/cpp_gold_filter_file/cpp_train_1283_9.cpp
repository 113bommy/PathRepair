#include <bits/stdc++.h>
const int maxBufSize = (10000000);
using namespace std;
long long int n, m, cnt1, cnt2;
long long int arr1[100005], arr2[100005], truth1[100005], truth2[100005],
    chk[100005];
vector<long long int> v1[100005], v2[100005];
string s;
long long int convert_to_int(string s) {
  long long int i, ret, len;
  len = s.length();
  ret = 0;
  for (i = 1; i <= len - 1; ++i) {
    ret = ret * 10 + (s[i] - '0');
  }
  return ret;
}
int main() {
  long long int i, j, a, b, c, cnt;
  cin >> n >> m;
  for (i = 1; i <= n; ++i) {
    cin >> s;
    a = convert_to_int(s);
    if (s[0] == '+') {
      arr1[a]++;
      cnt1++;
      v1[a].push_back(i);
      chk[i] = a;
    } else {
      arr2[a]++;
      cnt2++;
      v2[a].push_back(i);
      chk[i] = -a;
    }
  }
  cnt = 0;
  for (i = 1; i <= n; ++i) {
    a = arr1[i] + cnt2 - arr2[i];
    if (a == m) {
      b = v1[i].size();
      for (j = 0; j <= b - 1; ++j) {
        truth1[v1[i][j]]++;
      }
      b = v2[i].size();
      for (j = 0; j <= b - 1; ++j) {
        truth2[v2[i][j]]++;
      }
      cnt++;
    }
  }
  for (i = 1; i <= n; ++i) {
    if (truth1[i] == cnt) {
      cout << "Truth\n";
    } else if (truth2[i] == cnt) {
      cout << "Lie\n";
    } else if (truth1[i] == 0 && truth2[i] == 0) {
      if (chk[i] < 0) {
        cout << "Truth\n";
      } else {
        cout << "Lie\n";
      }
    } else {
      cout << "Not defined\n";
    }
  }
  return 0;
}
