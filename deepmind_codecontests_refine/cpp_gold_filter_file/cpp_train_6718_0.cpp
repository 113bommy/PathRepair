#include <bits/stdc++.h>
using namespace std;
int a[11];
int main() {
  int F, I, T;
  cin >> F >> I >> T;
  for (int i = 0; i < F; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < I; j++) {
      if (s[j] == 'Y') a[j]++;
    }
  }
  int A = 0;
  for (int i = 0; i < I; i++)
    if (a[i] >= T) A++;
  cout << A;
  return 0;
}
