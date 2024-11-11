#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv) {
  int n;
  cin >> n;
  string a, b;
  int counter = 1;
  cin >> a;
  for (int i = 1; i < n; i++) {
    cin >> b;
    if (a[1] == b[0]) counter++;
    a = b;
  }
  cout << counter << endl;
  return 0;
}
