#include <bits/stdc++.h>
using namespace std;
const int maxint = -1u >> 1;
int n;
char s[100000];
int num[100];
int main() {
  scanf("%d", &n);
  scanf("%s", s);
  int maxx = 0;
  for (int i = (1); i <= (n); ++i) {
    num[s[i - 1] - 'A']++;
    maxx = max(maxx, num[s[i - 1] - 'A']);
  }
  int b = 0;
  for (int i = 0; i < (26); ++i)
    if (num[i] == maxx) b++;
  long long ans = 1;
  for (int i = (1); i <= (n); ++i) ans = ans * b % 1000000007;
  cout << ans << endl;
  return 0;
}
