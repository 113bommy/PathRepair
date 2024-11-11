#include <bits/stdc++.h>
using namespace std;
long long int m, n, c = 0, k = 0, a = 0, b = 0, temp, MAX = 0, MIN = 999999999,
                    sum = 0;
long long int i, j;
int main() {
  string s;
  string x;
  cin >> s;
  cin >> x;
  for (i = 0, j = 0; i < s.size(); i++) {
    if (s[j] == x[i]) j++;
  }
  cout << j + 1 << endl;
}
