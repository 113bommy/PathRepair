#include <bits/stdc++.h>
using namespace std;
int main() {
  char s[101];
  int n, i, sum8 = 0, sum = 0, total = 0;
  cin >> n;
  cin >> s;
  for (i = 0; i < n; i++) {
    if (s[i] == '8') sum8++;
    sum++;
  }
  if (sum8 >= sum / 11)
    total = sum / 11;
  else
    total = sum8;
  cout << total << endl;
  return 0;
}
