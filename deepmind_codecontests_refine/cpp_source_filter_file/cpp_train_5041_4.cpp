#include <bits/stdc++.h>
using namespace std;
int sum[27];
int pos[27];
int n;
int main() {
  string str;
  cin >> str;
  int l = str.length();
  for (int i = 0; i < l; i++) {
    int t = str[i] - 'a';
    if (!pos[t]) n++;
    pos[t] = i + 1;
    int c[27];
    for (int j = 0; j < 27; j++) c[j] = pos[j];
    sort(c, c + 27);
    for (int j = 0; j < 27 && c[27 - j - 1]; j++) {
      sum[j + 1] += c[27 - j - 1] - c[27 - j - 2];
    }
  }
  cout << n << endl;
  for (int i = 1; i <= n; i++) {
    cout << sum[i] << endl;
  }
}
