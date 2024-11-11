#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k = 0;
  string home;
  cin >> n;
  cin >> home;
  for (int i = 0; i < n; i++) {
    string now;
    cin >> now;
    now = now.substr(5, 3);
    if (now == home) k++;
  }
  if (k == n - k)
    cout << "home";
  else
    cout << "contest";
  return 0;
}
