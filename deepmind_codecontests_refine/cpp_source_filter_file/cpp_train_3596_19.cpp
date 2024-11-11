#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  ;
  cin.tie(NULL);
  ;
  int n, x, b, c = 0;
  cin >> n >> x;
  char a;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    if (a == '+')
      x = x + b;
    else if (a == '-') {
      if (b <= x)
        x = x - b;
      else
        c++;
    }
  }
  cout << x << " " << c;
}
