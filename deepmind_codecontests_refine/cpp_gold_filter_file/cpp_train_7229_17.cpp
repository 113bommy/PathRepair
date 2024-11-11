#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int a = min(n, m);
  if (a % 2 == 0) {
    cout << "Malvika" << endl;
  } else {
    cout << "Akshat" << endl;
  }
}
