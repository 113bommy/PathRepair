#include <bits/stdc++.h>
using namespace std;
long nn[10001] = {0};
int main() {
  long n;
  cin >> n;
  for (long i = 1; i <= n; i++) nn[i] = i * i;
  int count = 0;
  for (int a = 1; 2 * a * a < n * n; a++)
    for (int b = a + 1; a * a + b * b <= n * n; b++)
      for (int c = sqrt(a * a + b * b); c <= sqrt(a * a + b * b) + 1; c++)
        if ((nn[a] + nn[b]) == nn[c]) {
          count++;
          break;
        }
  cout << count << endl;
}
