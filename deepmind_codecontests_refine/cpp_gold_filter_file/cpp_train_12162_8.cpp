#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C;
  cin >> A >> B >> C;
  cout << max(A, max(B, C))*9 + A + B + C << endl;
}
