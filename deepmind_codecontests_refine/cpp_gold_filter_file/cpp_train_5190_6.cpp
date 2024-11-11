#include <bits/stdc++.h>
using namespace std;

int main() {
  double A, B;
  cin >> A >> B;

  cout << ((A > B) ? "GREATER" : (A < B) ? "LESS" : "EQUAL") << "\n";
}