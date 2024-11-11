#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int v[1000010] = {0};
  int in = 0;
  int n = s.length();
  int fin = n - 1;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'l')
      v[fin--] = i + 1;
    else
      v[in++] = i + 1;
  }
  for (int i = 0; i < n; i++) cout << v[i] << endl;
  return 0;
}
