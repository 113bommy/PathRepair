#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[]) {
  int n, temp;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    if (temp == 1) {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
