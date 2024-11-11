#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  int k, sum = 0, max, sum1;
  cin >> s >> k;
  int a[26], l = s.length(), m;
  m = l + k;
  for (int i = 0; i < 26; i++) {
    cin >> a[i];
    if (max < a[i]) max = a[i];
  }
  for (int i = 0; i < s.length(); i++) sum += (a[s[i] - 'a']) * (i + 1);
  sum1 = ((m * (m + 1)) / 2) - ((l * (l + 1)) / 2);
  sum += sum1 * max;
  cout << sum;
}
