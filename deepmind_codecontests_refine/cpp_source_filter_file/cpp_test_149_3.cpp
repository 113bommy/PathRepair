#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    long long n, k, x;
    cin >> n >> k >> x;
    x--;
    string s;
    cin >> s;
    stack<long long> lst;
    int l[2005] = {0};
    int c = 0;
    s += '\n';
    for (int i = 0; i < n; i++) {
      if (s[i] == '*') {
        c++;
        l[c] = 1;
        while (s[i + 1] == '*') {
          l[c]++;
          i++;
        }
      }
    }
    for (int i = 1; i <= c; i++) {
      lst.push(x % (l[c] * k + 1));
      x /= (l[c] * k + 1);
    }
    for (int i = 0; i < n; i++) {
      if (s[i] == '*') {
        if (s[i + 1] != '*') {
          for (int i = 0; i < lst.top(); i++) {
            printf("b");
          }
          lst.pop();
        }
      } else
        printf("%c", s[i]);
    }
    puts("");
  }
  return 0;
}
