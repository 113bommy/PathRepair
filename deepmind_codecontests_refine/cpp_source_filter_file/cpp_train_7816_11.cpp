#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 1500;
long long int a[N], b[N];
int main() {
  long long int n;
  cin >> n;
  string s;
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    a[s[i] - 'a']++;
  }
  long long int t = 0;
  for (int i = 0; i < 26; i++) {
    if (a[i] >= 2) {
      t++;
    }
  }
  bool bb = 1;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] != s[i + 1]) {
      bb = 0;
    }
  }
  bool b = t;
  if (b || bb)
    cout << "YES";
  else
    cout << "NO";
}
