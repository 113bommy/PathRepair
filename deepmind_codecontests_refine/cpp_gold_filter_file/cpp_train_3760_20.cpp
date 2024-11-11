#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  string out;
  cin >> n;
  int p1 = 0, p2 = (int)1e9;
  string aux;
  cout << p2 << " 5" << endl;
  cin >> aux;
  for (int i = 1; i < n; i++) {
    int mid = (p1 + p2) / 2;
    cout << mid << " 5" << endl;
    cin >> out;
    if (out == aux)
      p2 = mid;
    else
      p1 = mid;
  }
  cout << p1 << " 0 " << p2 << " 10" << endl;
  return 0;
}
