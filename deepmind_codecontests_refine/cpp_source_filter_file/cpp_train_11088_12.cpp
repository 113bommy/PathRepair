#include <bits/stdc++.h>
using namespace std;
long long n, m, k, i, j;
string s;
int main() {
  cin >> n;
  cin >> s;
  for (i = 1; i < n; i++) {
    if (s[i - 1] != s[i]) k++;
  }
  cout << min(k + 2, n);
}
