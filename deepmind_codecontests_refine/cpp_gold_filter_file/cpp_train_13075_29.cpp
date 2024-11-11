#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, j, i = 0, count = 0, max = 100000000;
  string s1, s2;
  cin >> n >> m >> s1 >> s2;
  vector<int> a, b;
  while (i + n <= m) {
    count = 0;
    for (j = 0; j < n; j++) {
      if (s1[j] != s2[i + j]) {
        a.push_back(j + 1);
        count++;
      }
    }
    if (count < max) {
      max = count;
      b = a;
    }
    i++;
    a.clear();
  }
  cout << max << endl;
  for (i = 0; i < max; i++) cout << b[i] << " ";
  cout << endl;
  return 0;
}
