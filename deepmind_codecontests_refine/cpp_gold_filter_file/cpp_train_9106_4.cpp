#include <bits/stdc++.h>
using namespace std;
int main() {
  string S;
  int n;
  cin >> S >> n;
  int Size = S.size();
  if (Size % n != 0) {
    cout << "NO";
    return 0;
  }
  int Sub = Size / n;
  for (int i = 0; i < Size; i++) {
    if (S[i] != S[(i / Sub) * Sub + Sub - 1 - (i % Sub)]) {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES";
}
