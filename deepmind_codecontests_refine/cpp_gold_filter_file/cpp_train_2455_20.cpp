#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int ara[n];
  for (int i = 0; i < n; i++) cin >> ara[i];
  sort(ara, ara + n);
  if (n == 1)
    cout << ara[0];
  else if (n == 3)
    cout << ara[1];
  else
    cout << ara[2];
  cout << endl;
  return 0;
}
