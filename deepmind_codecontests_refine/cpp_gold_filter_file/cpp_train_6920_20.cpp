#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b;
  cin >> a >> b;
  long long c = (a + b) / 3;
  cout << min(min(b, a), c) << endl;
}
