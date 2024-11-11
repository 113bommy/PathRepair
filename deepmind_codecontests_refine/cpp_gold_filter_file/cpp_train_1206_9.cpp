#include <bits/stdc++.h>
using namespace std;
string a, b = "heidi";
long long i, j, k;
int main() {
  getline(cin, a);
  for (i = 0; i < a.size(); i++) {
    if (a[i] == b[k]) {
      k++;
    }
    if (k >= 5) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}
