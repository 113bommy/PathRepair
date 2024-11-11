#include <bits/stdc++.h>
using namespace std;
bool debug = 0;
int n, m, k;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
string direc = "RDLU";
long long ln, lk, lm;
char s[300105];
void fmain() {
  scanf("%s", s);
  if ((s[0] - '0') % 4 == 0) lk++;
  n = strlen(s);
  for (int i = 1; i < n; i++) {
    int x = (s[i] - '0') + 10 * (s[i - 1] - '0');
    if (x % 4 == 0) lk += i;
    if ((s[i] - '0') % 4 == 0) lk++;
  }
  cout << lk << endl;
}
int main() {
  fmain();
  return 0;
}
