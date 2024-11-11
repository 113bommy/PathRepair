#include <bits/stdc++.h>
using namespace std;
bool a[101][27];
int main() {
  int n, m;
  string tt;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> tt;
    for (int j = 0; j < m; j++) {
      a[j][(int)(tt[j] - 'A')] = true;
    }
  }
  long long mod = 1000000009;
  long long sum = 1;
  for (int i = 0; i < m; i++) {
    int numb = 0;
    for (int j = 0; j < 26; j++) {
      if (a[i][j]) numb++;
    }
    if (numb > 0) {
      sum = (sum * numb) % mod;
    }
  }
  cout << sum;
}
