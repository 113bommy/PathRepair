#include <bits/stdc++.h>
using namespace std;
int main() {
  int A, B;
  cin >> A >> B;
  cout << max(A+B, 2*A-1, 2*B-1) << endl;
}