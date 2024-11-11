#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7;
long long int n, ar[1000005], k, sum, m;
char s[1000005];
int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
  cin >> s + 1;
  n = strlen(s + 1);
  k++;
  for (int i = 1; i <= n; i++) {
    if (k == 1 && s[i] == 'h') k++;
    if (k == 2 && s[i] == 'e') k++;
    if (k == 3 && s[i] == 'i') k++;
    if (k == 4 && s[i] == 'd') k++;
    if (k == 5 && s[i] == 'i') k++;
  }
  if (k == 6)
    cout << "YES";
  else
    cout << "NO";
}
