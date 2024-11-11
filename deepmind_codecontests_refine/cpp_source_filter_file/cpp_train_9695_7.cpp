#include <bits/stdc++.h>
using namespace std;
int tab[101];
int main() {
  int n, result;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> tab[i];
  sort(tab + 1, tab + n + 1);
  for (int i = 2; i <= n; i += 2) {
    result += tab[i] - tab[i - 1];
  }
  cout << result;
  return 0;
}
