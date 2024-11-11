#include <bits/stdc++.h>
using namespace std;
string f;
int len;
int f1, f2, f3, f4;
int main() {
  cin >> f;
  len = f.size();
  if (len >= 5) f1 = true;
  for (int i = 0; i <= len; i++) {
    if (f[i] >= 'a' && f[i] <= 'z') f2 = true;
    if (f[i] >= 'A' && f[i] <= 'Z') f3 = true;
    if (f[i] >= '0' && f[i] <= '9') f4 = true;
  }
  if (f1 == true && f2 == true && f3 == true && f4 == true)
    printf("Correct");
  else
    printf("Too weak");
  return 0;
}
