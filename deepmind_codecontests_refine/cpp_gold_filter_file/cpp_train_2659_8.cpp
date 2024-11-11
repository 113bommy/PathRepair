#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a;
  cin >> n >> a;
  int sum = n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x > a) sum++;
  }
  cout << sum << endl;
}
