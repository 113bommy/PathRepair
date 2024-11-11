#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;
int row[MAX], col[MAX], n, sum = 0;
string s;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s;
    for (int j = 0; j < n; j++) {
      if (s[j] == 'C') {
        sum = row[j] + col[i], row[j]++, col[i]++;
      }
    }
  }
  cout << sum;
  return 0;
}
