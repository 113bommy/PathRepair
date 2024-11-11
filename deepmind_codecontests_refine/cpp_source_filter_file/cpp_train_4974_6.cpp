#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// const int d = 365;
int main() {
  int d;
  cin >> d;
  vector<int> c(26);
  for (int i = 0; i < 26; i++) {
    cin >> c[i];
  }
  vector<vector<int>> s(d, vector<int>(26));
  for (int i = 0; i < d; i++) {
    for (int j = 0; j < 26; j++) {
      cin >> s[i][j];
    }
  }

  for (int i = 0; i < d; i++)
  {
    cout << i % 26 + 1 << end;
  }
  

  return 0;
}