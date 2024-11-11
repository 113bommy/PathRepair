#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  if (n > min(m, k)) {
    cout << "No";
  } else {
    cout << "Yes";
  }
}
