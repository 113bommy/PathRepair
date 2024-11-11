#include <bits/stdc++.h>
using namespace std;
int main() {
  long n, i, t, *a, sum = 0;
  cin >> n >> t;
  a = (long*)malloc(n * sizeof(long));
  for (int i = 1; i < n; i++) scanf("%ld", a + i);
  i = 1;
  while (i < t) {
    if (*(a + i) + i == t) sum++;
    i += *(a + i);
  }
  if (sum != 0)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
