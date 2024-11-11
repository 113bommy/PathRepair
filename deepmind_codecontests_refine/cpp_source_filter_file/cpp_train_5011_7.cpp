#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 9;
const double pi = acos(-1.0);
double esp = 1e-6;
const int N = 2e5 + 9;
const int INF = 0x3f3f3f3f;
char s[N];
int main() {
  int n;
  cin >> n;
  scanf("%s", s);
  int cnt = 0;
  for (int i = 1; i < n; i++) {
    if (i < n - 1) {
      if (s[i] == s[i - 1]) {
        cnt++;
        if (s[i] == 'R' && s[i + 1] == 'R') {
          s[i] = 'G';
        } else if (s[i] == 'R' && s[i + 1] == 'G') {
          s[i] = 'B';
        } else if (s[i] == 'R' && s[i + 1] == 'B') {
          s[i] = 'G';
        } else if (s[i] == 'G' && s[i + 1] == 'G') {
          s[i] = 'B';
        } else if (s[i] == 'G' && s[i + 1] == 'R') {
          s[i] = 'B';
        } else if (s[i] == 'G' && s[i + 1] == 'B') {
          s[i] = 'R';
        }
        if (s[i] == 'B' && s[i + 1] == 'B') {
          s[i] = 'G';
        } else if (s[i] == 'B' && s[i + 1] == 'G') {
          s[i] = 'R';
        } else if (s[i] == 'B' && s[i + 1] == 'R') {
          s[i] = 'G';
        }
        i++;
      }
    } else {
      if (s[i] == s[i - 1]) {
        cnt++;
        if (s[i] == 'R') {
          s[i] = 'G';
        } else if (s[i] == 'B') {
          s[i] = 'G';
        } else
          s[i] = 'R';
      }
    }
  }
  cout << cnt << endl;
  for (int i = 0; i < n; i++) {
    printf("%c", s[i]);
  }
  cout << endl;
  return 0;
}
