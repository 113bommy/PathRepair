#include <bits/stdc++.h>
using namespace std;
bool Check(long long suml, long long sumr, long long fl, long long fr) {
  long long M = suml + fl * 9 - sumr;
  long long m = suml - (sumr + fr * 9);
  if ((M + m) / 2)
    return true;
  else
    return false;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  string s;
  cin >> s;
  long long fl = 0;
  long long fr = 0;
  long long suml = 0;
  long long sumr = 0;
  for (long i = 0; i < n / 2; i++) {
    if (s[i] == '?')
      fl += 1;
    else
      suml += s[i] - '0';
  }
  for (long i = n / 2; i < n; i++) {
    if (s[i] == '?')
      fr += 1;
    else
      sumr += s[i] - '0';
  }
  if (Check(suml, sumr, fl, fr))
    cout << "Bicarp";
  else
    cout << "Monocarp";
  return 0;
}
