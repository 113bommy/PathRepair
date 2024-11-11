#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int l = s.length();
  vector<char> arr;
  for (int i = 0; i < l; i++) {
    if (s[i] != '+') arr.push_back(s[i]);
  }
  sort(arr.begin(), arr.end());
  for (int i = 0; i < arr.size() - 1; i++) {
    cout << arr[i] << '+';
  }
  cout << arr[arr.size() - 1];
}
