#include <bits/stdc++.h>
using namespace std;
int ans;
int main() {
  int n, m, a;
  cin >> n >> m >> a;
  if (n <= min(m, a)) {
    cout << "Yes";
  } else {
    cout << "No";
  }
}
