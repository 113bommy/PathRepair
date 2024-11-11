#include <bits/stdc++.h>
using namespace std;

int main() {
  string s, t;
  cin >> s >> t;
  sort(s.begin(), s.end());
  sort(t.rbegin(), t.rend());
  if (t > s) {
    cout << "Yes";
  } else {
    cout << "No";
  }
}
