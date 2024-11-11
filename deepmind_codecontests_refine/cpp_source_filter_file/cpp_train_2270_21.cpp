#include <bits/stdc++.h>
using namespace std;
int main() {
  int A, B;
  cin >> A >> B;
  string S;
  cin >> S;
  S[B--] += 32;
  cout << S << endl;
}
