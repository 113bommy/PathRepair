#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  (cout << min(a, b) << " " << max((a - min(a, b)) / 2, (a - min(a, b)) / 2));
}
