#include <bits/stdc++.h>
using namespace std;
bool a[101 * 1000];
int main() {
  int n;
  cin >> n;
  n++;
  for (int i = 2; i <= n; i++)
    if (!a[i])
      for (int j = 2 * i; j <= n; j += i) a[j] = true;
  if (n < 3)
    cout << 1 << endl;
  else
    cout << 2 << endl;
  for (int i = 2; i <= n; i++)
    if (!a[i])
      cout << "1 ";
    else
      cout << "2 ";
  cout << endl;
  return 0;
}
