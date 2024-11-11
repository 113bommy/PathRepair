#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C;
  cin >> A >> B >> C;
  cout << ((max({A, B, C})==(A+B+C-max({A, B, C})))?"Yes":"No") << endl;
}
