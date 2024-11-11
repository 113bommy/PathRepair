#include <bits/stdc++.h>
using namespace std;
const int N = 200010, mod = 1e9 + 7;
int T;
int n, num, st, a[N];
string s;
int main() {
  cin >> T;
  while (T--) {
    cin >> n >> s;
    num = n, st = 0;
    for (int i = 0; i < n; i++)
      if (i == n - 1 || s[i] == '>') {
        for (int j = i; j >= st; j--) a[j] = num--;
        st = i + 1;
      }
    for (int i = 0; i < n; i++) cout << a[i] << ' ';
    puts("");
    num = 1, st = 0;
    for (int i = 0; i < n; i++)
      if (i == n - 1 || s[i] == '<') {
        for (int j = i; j >= st; j--) a[j] = num++;
        st = i + 1;
      }
    for (int i = 0; i < n; i++) cout << a[i] << ' ';
    puts("");
  }
  return 0;
}
