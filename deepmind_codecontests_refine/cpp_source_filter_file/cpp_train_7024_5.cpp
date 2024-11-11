#include <bits/stdc++.h>
using namespace std;
const long long M = (long long)(1e+7);
long long MOD(long long num) { return (num % M + M) % M; }
int n;
char str;
long long fact[100010];
int nums[4];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    do {
      cin >> str;
    } while ((str < 'A') || (str > 'T'));
    if (str == 'A')
      nums[0]++;
    else if (str == 'C')
      nums[1]++;
    else if (str == 'G')
      nums[2]++;
    else
      nums[3]++;
  }
  int meg = 0;
  for (int i = 0; i < 4; i++) meg = max(meg, nums[i]);
  int posa = 0;
  for (int i = 0; i < 4; i++)
    if (nums[i] == meg) posa++;
  long long res = 1;
  for (int i = 1; i <= n; i++) res = MOD(res * posa);
  cout << res << '\n';
  return 0;
}
