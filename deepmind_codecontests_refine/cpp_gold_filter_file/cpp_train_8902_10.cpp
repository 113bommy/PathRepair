#include <bits/stdc++.h>
using namespace std;
int main() {
  int siz;
  string s;
  cin >> siz >> s;
  int n = s.length();
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (s[cnt] == '>') {
      cnt += arr[cnt];
    } else if (s[cnt] == '<') {
      cnt -= arr[cnt];
    }
    if (cnt >= siz || cnt < 0) {
      cout << "FINITE" << endl;
      return 0;
    }
  }
  cout << "INFINITE" << endl;
  return 0;
}
