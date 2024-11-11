#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int k;
  cin >> k;
  long long int rem = k % 2;
  long long int eight = k / 2;
  vector<char> v;
  for (int i = 0; i < eight; i++) {
    v.push_back('8');
  }
  for (int i = 0; i < rem; i++) {
    v.push_back('9');
  }
  if (v.size() <= 18) {
    for (int i = 0; i < v.size(); i++) {
      cout << v[i];
    }
  } else {
    cout << "-1";
  }
  return 0;
}
