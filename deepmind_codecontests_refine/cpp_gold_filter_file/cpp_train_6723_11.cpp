#include <bits/stdc++.h>
using namespace std;
int main() {
  unsigned long long A, B;
  cin >> A >> B;
  unsigned long long Y = (A - B) >> 1;
  unsigned long long X = A - Y;
  if (X > Y) swap(X, Y);
  if (((X + Y) == A) && ((X ^ Y) == B))
    cout << X << " " << Y;
  else
    cout << "-1";
exit:
  return (0);
}
