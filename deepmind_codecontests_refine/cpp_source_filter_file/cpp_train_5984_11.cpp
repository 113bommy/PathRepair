#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int l = s.size();
  long long frq[125] = {}, c = 0;
  sort(s.begin(), s.end());
  for (int i = 0; i < l; i++) {
    frq[s[i]]++;
  }
  for (int i = 4; i <= 122; i++) {
    if (frq[i] > 1)
      c = frq[i] * frq[i];
    else if (frq[i] == 1)
      c++;
  }
  cout << c << endl;
  return 0;
}
