#include <bits/stdc++.h>
using namespace std;
int n, t[1001];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    t[i] = i * (i + 1) / 2;
  }
  int i = 1;
  while (n != t[i] && i <= n) {
    i++;
  }
  if (n == t[i])
    cout << "YES";
  else
    cout << "NO";
}
