#include <bits/stdc++.h>
using namespace std;
int main() {
  int n1, n2, i;
  cin >> n1 >> n2;
  if (n1 > n2) {
    i = n2;
  } else {
    i = n1;
  }
  if (i % 2 == 0) {
    cout << "malavika";
  } else {
    cout << "Akshit";
  }
  return 0;
}
