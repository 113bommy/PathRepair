#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b;
  cin >> n;
  bool bo = false;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    if (a != b) bo = true;
  }
  if (bo)
    cout << "Happy Alex";
  else
    cout << "Poor Alex";
}
