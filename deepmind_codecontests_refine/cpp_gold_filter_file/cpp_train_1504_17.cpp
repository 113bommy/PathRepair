#include <bits/stdc++.h>
using namespace std;
long long int a[100];
int main() {
  long long int x;
  cin >> x;
  long long int low = -2000000000;
  long long int hig = 2000000000;
  for (int i = 1; i <= x; i++) {
    string s;
    long long int n;
    char ans;
    cin >> s >> n >> ans;
    if (s == ">=") {
      if (ans == 'Y') {
        low = max(low, n);
      } else {
        hig = min(hig, n - 1);
      }
    }
    if (s == "<=") {
      if (ans == 'Y') {
        hig = min(hig, n);
      } else {
        low = max(low, n + 1);
      }
    }
    if (s == ">") {
      if (ans == 'Y') {
        low = max(low, n + 1);
      } else {
        hig = min(hig, n);
      }
    }
    if (s == "<") {
      if (ans == 'Y') {
        hig = min(hig, n - 1);
      } else {
        low = max(low, n);
      }
    }
  }
  if (low > hig)
    return cout << "Impossible", 0;
  else {
    cout << low << endl;
    return 0;
  }
}
