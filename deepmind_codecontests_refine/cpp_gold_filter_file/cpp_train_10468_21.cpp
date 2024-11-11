#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int d;
  char c;
  cin >> c >> d;
  if ((d == 1 || d == 8) && c == 'a')
    cout << "3";
  else if ((d == 1 || d == 8) && c == 'h')
    cout << "3";
  else if (d == 1 || d == 8 && c != 'a' && c != 'h')
    cout << "5";
  else if (c == 'a' || c == 'h' && d != '1' && d != 8)
    cout << "5";
  else
    cout << "8";
  return 0;
}
