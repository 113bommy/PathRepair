#include <bits/stdc++.h>
using namespace std;
int A[10];
int main() {
  int a;
  for (int i = 0; i < 6; i++) cin >> a, A[a]++;
  bool z4 = 0;
  int k;
  for (int i = 1; i <= 9; i++)
    if (A[i] >= 4) z4 = 1, k = i;
  if (!z4)
    cout << "Alien";
  else {
    if (A[k] == 6) cout << "Elephant";
    if (A[k] == 5) cout << "Bear";
    int s = 0;
    for (int i = 1; i <= 9; i++)
      if (A[i]) s++;
    if (A[k] == 4 && s == 3) cout << "Bear";
    if (A[k] == 4 && s == 2) cout << "Elephant";
  }
}
