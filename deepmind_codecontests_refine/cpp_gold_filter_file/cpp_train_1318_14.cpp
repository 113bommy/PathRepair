#include <bits/stdc++.h>
using namespace std;
int const maxn = 100000;
int A[maxn], n, p = 0, s = 0;
int main() {
  string str;
  cin >> str;
  for (int i = 0; i < str.length(); i++) {
    if (str[i] == '-')
      s++;
    else
      p++;
  }
  if (s == 0 || p == 0 || p == 1) {
    cout << "YES";
    return 0;
  }
  if (s % p == 0) {
    cout << "YES";
    return 0;
  }
  cout << "NO";
}
