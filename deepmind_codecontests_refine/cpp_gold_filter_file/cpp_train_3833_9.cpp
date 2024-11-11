#include <bits/stdc++.h>
using namespace std;

int main() {
  long A, B, C;
  cin >> A >> B >> C;
  cout << min((A + B + 1), C) + B << "\n";
}