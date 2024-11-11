#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, k, n;
  cin >> k >> n;
  vector<int> v[26];
  char vis[26] = {0};
  char str[100010] = {0};
  for (i = 0; i < n; i++) {
    char ch;
    cin >> ch;
    v[ch - 'a'].push_back(i);
    str[i] = ch;
    vis[ch - 'a'] = 1;
  }
  for (int i1 = 0; i1 < k; i1++) {
    char str1[100010] = {0};
    cin >> str1;
    long long sum = 0;
    int len = strlen(str1);
    for (i = 0; i < len; i++) {
      if ((i < n) && (str1[i] == str[i])) {
        continue;
      } else if (vis[str1[i] - 'a'] == 0) {
        sum += len;
      } else if (vis[str1[i] - 'a'] == 1) {
        long long min = 1000000000000;
        long long x;
        for (int j = 0; j < v[str1[i] - 'a'].size(); j++) {
          x = abs(v[str1[i] - 'a'][j] - i);
          if (min > x) {
            min = x;
          }
        }
        sum += min;
      }
    }
    cout << sum << endl;
  }
  return 0;
}
