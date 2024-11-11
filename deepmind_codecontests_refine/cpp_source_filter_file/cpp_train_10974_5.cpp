#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  char c;
  cin >> n;
  long long int temp;
  temp = pow(n, 2) + 1;
  temp = temp / 2;
  cout << temp << endl;
  long long int i, j;
  for (i = 0; i < n; i++) {
    if (i % 2 == 0)
      c = 'C';
    else
      c = '*';
    for (j = 0; j < n; j++) {
      cout << c;
      if (c == 'C')
        c = '*';
      else
        c = 'C';
    }
    cout << endl;
  }
  return 0;
}
