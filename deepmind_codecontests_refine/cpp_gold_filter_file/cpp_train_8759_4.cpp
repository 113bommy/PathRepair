#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int min = INT_MAX, res;
  char a[] = {'A', 'C', 'T', 'G'};
  for (int i = 0; i < n - 3; i++) {
    res = 0;
    for (int j = 0; j < 4; j++) {
      if (abs(s[i + j] - a[j]) < 13)
        res += abs(s[i + j] - a[j]);
      else
        res += 26 - abs(s[i + j] - a[j]);
    }
    if (res < min) min = res;
  }
  cout << min << endl;
  return 0;
}
