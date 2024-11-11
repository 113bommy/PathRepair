#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int min = -1000000001, max = 1000000001;
  int query;
  cin >> query;
  string s;
  int n;
  char c;
  for (int i = 0; i < query; i++) {
    cin >> s >> n >> c;
    if (s == ">=") {
      if (c == 'Y') {
        if (min < n) min = n;
      } else {
        if (max > n) max = n;
      }
    } else if (s == "<") {
      if (c == 'Y') {
        if (max > n - 1) max = n - 1;
      } else {
        if (min < n) min = n;
      }
    } else if (s == ">") {
      if (c == 'Y') {
        if (min < n + 1) min = n + 1;
      } else {
        if (max > n) max = n;
      }
    } else {
      if (c == 'Y') {
        if (max > n) max = n;
      } else {
        if (min < n + 1) min = n + 1;
      }
    }
  }
  if (min <= max)
    cout << min;
  else
    cout << "Impossible";
  cout << '\n';
}
