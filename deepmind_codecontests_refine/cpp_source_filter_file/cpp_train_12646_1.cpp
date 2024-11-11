#include <bits/stdc++.h>
using namespace std;
int main() {
  int arr[27], a, n;
  string s;
  cin >> n >> s;
  for (int i = 0; i < 27; i++) arr[i] = 0;
  for (int i = 0; i < n; i++) {
    a = s[i];
    if (a < 97) a = a + 32;
    arr[a - 97] = 1;
  }
  a = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] == 1) a++;
  }
  if (a == 26)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
