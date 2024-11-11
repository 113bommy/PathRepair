#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, t;
  cin >> n >> t;
  if (n == 1 && t == 10)
    cout << "-1" << endl;
  else {
    cout << t;
    for (int i = (t / 10) + 1; i < n; i++) cout << "0";
    cout << endl;
  }
  return 0;
}
