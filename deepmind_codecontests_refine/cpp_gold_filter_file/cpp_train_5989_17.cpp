#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;
int col[MAX], row[MAX], n, sum;
string s;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s;
    for (int j = 0; j < n; j++) {
      if (s[j] == 'C') {
        sum += col[j] + row[i], col[j]++, row[i]++;
      }
    }
  }
  cout << sum;
  return 0;
}
