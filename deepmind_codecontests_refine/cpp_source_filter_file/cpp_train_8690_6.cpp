#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv) {
  int n;
  cin >> n;
  bool f = false;
  int k = 1, l = n;
  for (int i = 1; i <= n; i++) {
    if (f == false) {
      cout << k << " ";
      f = !f;
      k++;
    } else {
      cout << l;
      f = !f;
      l--;
    }
  }
  return 0;
}
