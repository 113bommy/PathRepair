#include <bits/stdc++.h>
using namespace std;
vector<long long> a;
int main() {
  long long n;
  cin >> n;
  string s;
  for (long long o = 0; o < n; o++) {
    cin >> s;
    long long ss = s.size();
    if (ss == 1) {
      cout << "YES" << '\n';
      continue;
    }
    a.clear();
    a.resize(26, 0);
    for (long long i = 0; i < ss; i++) {
      long long c = s[i] - 'a';
      a[c]++;
    }
    bool p = true;
    long long k = 0;
    long long i = 0;
    while (i < 26) {
      if (a[i] == 2) {
        p = false;
        break;
      }
      if (a[i] == 1) {
        k++;
        if (k != 1) {
          p = false;
          break;
        };
        long long j;
        for (j = i + 1; a[j] == 1; j++)
          ;
        i = j - 1;
      }
      i++;
    }
    if (p)
      cout << "YES" << '\n';
    else
      cout << "NO" << '\n';
  }
}
