#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int k;
    k = n / 2;
    string str = "";
    for (int i = 0; i < k; i++) {
      str += 'a';
    }
    str += 'b';
    for (int i = 0; i < k - 1; i++) {
      str += 'a';
    }
    if (n % 2) {
      str += 'z';
    }
    cout << str << endl;
  }
}
