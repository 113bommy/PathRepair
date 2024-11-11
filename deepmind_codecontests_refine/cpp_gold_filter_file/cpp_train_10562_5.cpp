#include <bits/stdc++.h>
using namespace std;
int n, m;
string s1, s2;
int main() {
  cin >> n >> m;
  cin >> s1 >> s2;
  if (s1[0] == '>') {
    if (s2[m - 1] == '^') {
      cout << "NO";
      return 0;
    }
  } else {
    if (s2[0] == '^') {
      cout << "NO";
      return 0;
    }
  }
  if (s1[n - 1] == '>') {
    if (s2[m - 1] == 'v') {
      cout << "NO";
      return 0;
    }
  } else {
    if (s2[0] == 'v') {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES";
}
