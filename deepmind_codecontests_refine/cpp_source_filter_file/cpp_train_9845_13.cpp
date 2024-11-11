#include <bits/stdc++.h>
using namespace std;
string x;
int main() {
  int a, A, D, i = 0;
  cin >> a >> x;
  for (int i = 0; i < a; i++) {
    if (x[i] == 'A')
      A++;
    else
      D++;
  }
  if (D < A)
    cout << "Anton" << endl;
  else if (D > A)
    cout << "Danik" << endl;
  else
    cout << "Friendship" << endl;
}
