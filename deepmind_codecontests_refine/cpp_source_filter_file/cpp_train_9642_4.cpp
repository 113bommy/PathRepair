#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  int n, a, b;
  cin >> n;
  string str;
  cin >> str;
  for (int i = 0; i < n - 1; i++) {
    if (str[i] == 'S' && str[i + 1] == 'F')
      a++;
    else if (str[i] == 'F' && str[i + 1] == 'S')
      b++;
  }
  if (a > b)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
