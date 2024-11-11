#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<char> v;
  int i = 0;
  int j = 1;
  int sum = -1;
  while (sum < n - 1) {
    sum = sum + j;
    v.push_back(s[sum]);
    j++;
  }
  for (auto it = v.begin(); it != v.end(); it++) {
    cout << *it;
  }
}
