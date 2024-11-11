#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
long long int c[17000][600];
int n;
map<int, int> number;
map<int, int>::iterator it;
void findc() {
  c[0][0] = 1;
  for (int i = 1; i < 17000; i++)
    for (int j = 0; j <= i && j < 600; j++) {
      if (j == 0 || j == i)
        c[i][j] = 1;
      else
        c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
    }
}
int main() {
  findc();
  int num;
  int a;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a);
    for (int j = 2; j * j <= a; j++) {
      while (a % j == 0) {
        a /= j;
        number[j]++;
      }
    }
    if (a > 1) number[a]++;
  }
  long long ans = 1;
  for (it = number.begin(); it != number.end(); it++) {
    int t = (*it).second;
    ans = (ans * c[t + n - 1][n - 1]) % mod;
  }
  cout << ans << endl;
  return 0;
}
