#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  int t;
  cin >> t;
  while (t--) {
    string n;
    cin >> n;
    n.size() > 9 ? cout << n[0] << n.size() - 2 << n[n.size() - 1] << endl
                 : cout << n << endl;
  }
  return 0;
}
