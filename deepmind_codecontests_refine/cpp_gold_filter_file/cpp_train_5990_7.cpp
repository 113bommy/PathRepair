#include <bits/stdc++.h>
using namespace std;
map<char, vector<string>> s;
long long func(char a, long long n) {
  if (n == 2) {
    return s[a].size();
  } else {
    long long suma = 0;
    for (string q : s[a]) {
      suma += func(q[0], n - 1);
    }
    return suma;
  }
}
int main() {
  long long n, q, i;
  scanf("%lld", &n);
  scanf("%lld", &q);
  char a;
  string b;
  for (i = 0; i < q; i++) {
    cin >> b >> a;
    s[a].push_back(b);
  }
  cout << func('a', n);
}
