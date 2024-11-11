#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, r;
  cin >> a >> b >> r;
  if (b < a) a = b;
  if (a < 2 * r)
    cout << "Second" << endl;
  else
    cout << "First" << endl;
}
