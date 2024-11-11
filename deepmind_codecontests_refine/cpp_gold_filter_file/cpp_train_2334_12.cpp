#include <bits/stdc++.h>
using namespace std;
int main() {
  char a;
  int A[15], Ans;
  fill_n(A, 15, 0);
  cin >> Ans;
  for (int i = 0; i < 16; i++) {
    cin >> a;
    if (a != '.')
      a -= '0';
    else
      a = 0;
    A[a]++;
  }
  for (int i = 1; i < 15; i++) {
    if (A[i] > (Ans * 2)) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}
