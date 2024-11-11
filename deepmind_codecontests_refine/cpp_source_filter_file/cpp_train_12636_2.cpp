#include <bits/stdc++.h>
using namespace std;
int n;
int a[1000000];
int main(int argc, char *argv[]) {
  cin >> n;
  int h;
  for (int i = 1; i <= n; i++) a[i] = i;
  for (int i = 2; i <= n; i++)
    for (int j = n / i; j >= 0; j--)
      a[min(j * i + i + i - 1, n + i - 1)] = a[i * j + i - 1];
  for (int i = n - 1; i < 2 * n - 1; i++) cout << a[i] << " ";
  cout << endl;
  return 0;
}
