#include <bits/stdc++.h>
using namespace std;
int main() {
  int A, B;
  cin >> A >> B;
  cout << max({A+B, A*2-1, B*2-1}) << endl;
}
