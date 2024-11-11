#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, k = 0, j, l[4], h = 1;
  cin >> n;
  string s;
  cin >> s;
  memset(l, 0, sizeof l);
  for (int i = 0; i < n; i++) {
    if (s[i] == 'A') l[0]++;
    if (s[i] == 'C') l[1]++;
    if (s[i] == 'T') l[2]++;
    if (s[i] == 'G') l[3]++;
  }
  j = max(max(l[0], l[1]), max(l[2], l[3]));
  for (int i = 0; i < 4; i++) {
    if (l[i] == j) k++;
  }
  for (int i = 0; i < n; i++) h = (h * k) % 100000007;
  cout << h;
}
