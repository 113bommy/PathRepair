#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int k = 0;
  for (size_t i = 0; i < s.size(); i++) k += s[i] == 'A';
  if (k > n - k) {
    cout << "Anton" << endl;
  } else if (k == n - k) {
    cout << "Friendship" << endl;
  } else {
    cout << "Danik" << endl;
  }
  return 0;
}
