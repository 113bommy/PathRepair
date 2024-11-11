#include <bits/stdc++.h>
using namespace std;

int main() {
  string A, B;
  cin >> A >> B;
  A += B;
  int tmp = stoi(A);
  cout << ((sqrt(tmp) == (int) sqrt(tmp)) ? "Yes" : "No") << "\n";
}