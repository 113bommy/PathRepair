#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, num;
  string s, f;
  int a = -1000000100, b = 1000000100;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s >> num >> f;
    if (s == ">=") {
      if (f == "Y")
        a = max(a, num);
      else
        b = min(b, num - 1);
    } else if (s == "<=") {
      if (f == "Y")
        b = min(b, num);
      else
        a = max(a, num + 1);
    } else if (s == "<") {
      if (f == "Y")
        b = min(b, num - 1);
      else
        a = max(a, num);
    } else if (s == ">") {
      if (f == "Y")
        a = max(a, num + 1);
      else
        b = min(b, num);
    }
  }
  if (a > b)
    cout << "Impossible\n";
  else
    cout << a << endl;
  return 0;
}
