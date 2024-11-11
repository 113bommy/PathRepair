#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, k;
  string s;
  cin >> n >> k >> s;
  for (char i = 'a'; i <= 'z' && k > 0; i++) {
    for (long long int j = 0; j < n && k > 0; j++) {
      if (s[j] == i) {
        s[j] = '#';
        k--;
      }
    }
  }
  for (long long int h = 0; h < n; h++) {
    if (s[h] != '#') cout << s[h];
  }
  cout << endl;
}
