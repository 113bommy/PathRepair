#include <bits/stdc++.h>
using namespace std;
int main() {
  unsigned long long a, b, c, d[1000001] = {0}, count = 0;
  for (int i = 1; i <= 1000001; i++)
    for (int j = i; j < 1000001; j += i) ++d[j];
  cin >> a >> b >> c;
  for (int i = 1; i <= a; i++)
    for (int j = 1; j <= b; j++)
      for (int k = 1; k <= c; k++) count += d[i * j * k];
  cout << count << endl;
}
