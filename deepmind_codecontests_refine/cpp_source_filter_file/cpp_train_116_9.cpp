#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  string s;
  cin >> s;
  long long ind = 0;
  while (ind < n - 1) {
    if (s[ind] > s[ind + 1]) {
      break;
    }
    ind++;
  }
  if (ind >= n - 1) {
    cout << "NO";
    return 0;
  }
  cout << "YES\n";
  cout << ind << " " << ind + 1;
  return 0;
}
