#include <bits/stdc++.h>
using namespace std;
int main() {
  int t[101] = {};
  for (int i = 2; i <= 10; ++i)
    for (int j = i * i; j < 101; j += i) t[i] = 1;
  int ff = 0;
  int b = 2;
  for (int i = 2; i <= 51; ++i) {
    if (t[i] == 0) {
      cout << i << "\n";
      fflush(stdout);
      string a;
      cin >> a;
      if (a == "yes") {
        ++ff;
        b = i;
      }
    }
  }
  if (ff == 1 && b <= 10) {
    cout << b * b << "\n";
    fflush(stdout);
    string a;
    cin >> a;
    if (a == "yes") ++ff;
  }
  if (ff >= 2)
    cout << "composite";
  else
    cout << "prime";
}
