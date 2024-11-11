#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char s1, s2;
      cin >> s1 >> s2;
      if ((s1 == '1') || (s1 == '1')) sum++;
    }
  }
  cout << sum;
}
