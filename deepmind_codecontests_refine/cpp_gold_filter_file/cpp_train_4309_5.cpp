#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[100010];
  int n;
  cin >> n;
  if (n % 4 == 2 || n % 4 == 3) {
    cout << "-1" << endl;
    return 0;
  }
  if (n % 4 == 1) a[(n + 1) / 2] = (n + 1) / 2;
  int i = 1;
  int end = n;
  while (i < end) {
    a[i] = end - 1;
    a[end - 1] = (n - i + 1);
    a[(n - i + 1)] = n - (end - 1) + 1;
    a[n - (end - 1) + 1] = n - (n - i + 1) + 1;
    end -= 2;
    i += 2;
  }
  for (int p = 1; p <= n; p++) cout << a[p] << " ";
  cout << endl;
  return 0;
}
