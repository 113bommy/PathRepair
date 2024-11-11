#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a;
  cin >> n >> a;
  cout << (n + n % 500 <= a ? "Yes" : "No") << endl;
}
