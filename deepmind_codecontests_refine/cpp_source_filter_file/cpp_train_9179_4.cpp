#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j;
  cin >> n;
  int k = n / 2;
  string s;
  cin >> s;
  int count = 0;
  for (i = 0; i < n; i++) {
    char a = s[i], b = s[i + 1];
    if (a == 'a' && b == 'a')
      s[i + 1] = 'b', count++;
    else if (a == 'b' && b == 'b')
      s[i] = 'a', count++;
  }
  cout << count << endl;
  cout << s;
}
