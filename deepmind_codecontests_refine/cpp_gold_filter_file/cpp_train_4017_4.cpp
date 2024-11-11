#include <bits/stdc++.h>
using namespace std;
int main() {
  string a, b;
  cin >> a >> b;
  int A = a.length(), B = b.length();
  cout << ((a == b) ? (-1) : (max(A, B)));
}
