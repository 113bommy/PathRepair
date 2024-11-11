#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  long long n, i, j, count = 0;
  cin >> s;
  int b[255] = {0};
  n = s.length();
  count = n;
  for (i = 0; i < n; i++) {
    b[int(s[i])]++;
  }
  for (i = 45; i < 123; i++) {
    count += (b[i] * (b[i] - 1));
  }
  cout << count << endl;
  return 0;
}
