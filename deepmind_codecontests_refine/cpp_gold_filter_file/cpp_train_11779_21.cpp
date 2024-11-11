#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c;
  int A, B, C;
  cin >> A >> B >> C;
  cin >> a >> b >> c;
  if (a >= A && (a - A) + b >= B && a + b + c - A - B >= C)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
