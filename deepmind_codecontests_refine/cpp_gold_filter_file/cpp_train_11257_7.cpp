#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
const int inf = 0x7f7f7f7f;
const long long mod = 100000007;
char a[210000];
char str[210000];
string t;
char *fact(int s, int e) {
  int k = 0;
  for (int i = s; i < e; i++) a[k++] = str[i];
  a[k++] = '\n';
  return a;
}
int main() {
  int n, k;
  cin >> n >> k;
  cin >> str;
  map<string, int> q;
  for (int i = 0; i < n;) {
    int s = i;
    bool flag = true;
    for (int j = i + 1; j < k + i; j++) {
      if (str[s] != str[j]) {
        i = j;
        flag = false;
        break;
      }
    }
    if (flag) q[t = fact(i, i + k)]++, i += k;
  }
  int ans = 0;
  for (map<string, int>::iterator iter = q.begin(); iter != q.end(); iter++)
    ans = max(ans, iter->second);
  cout << ans << endl;
}
