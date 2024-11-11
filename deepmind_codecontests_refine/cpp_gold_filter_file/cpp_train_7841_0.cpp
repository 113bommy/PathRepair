#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, c;
  cin >> n;
  c = n;
  for (int i = 2; i * i <= n; i++)
    while (n % i == 0) n /= i, c += n;
  if (n > 1) c++;
  cout << c << endl;
  return 0;
}
