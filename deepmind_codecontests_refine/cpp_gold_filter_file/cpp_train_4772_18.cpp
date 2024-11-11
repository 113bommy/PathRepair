#include <bits/stdc++.h>
using namespace std;

int main() {
  string a, b;
  cin >> a >> b;

  sort(a.begin(), a.end());
  sort(b.rbegin(), b.rend());

  if (a < b) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
