#include <bits/stdc++.h>
using namespace std;
string s = "";
stringstream file(s);
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  int N = (n + 2) / 2;
  cout << N << '\n';
  int i = 1, j = 1, k = 0;
  while (i != N || j != N) {
    cout << i << " " << j << '\n';
    if ((k++) % 2)
      i++;
    else
      j++;
  }
  if (n % 2) cout << N << " " << N << '\n';
  return 0;
}
