#include <bits/stdc++.h>
using namespace std;
string compare(string x) {
  if (x.size() == 1) return x;
  string a = compare(string(x, 0, x.size() / 2));
  string b = compare(string(x, x.size() / 2, x.size()));
  if (a < b)
    return a + b;
  else
    return b + a;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string x, y;
  cin >> x >> y;
  x = compare(x);
  y = compare(y);
  if (x == y)
    cout << "YES";
  else
    cout << "NO";
}
