#include <bits/stdc++.h>
using namespace std;
int main() {
  string a;
  cin >> a;
  int k = 0;
  for (int i = 0; i < a.length(); i++)
    if (a[i] == 'a') k++;
  if (k >= a.length() / 2) {
    cout << a.length();
  } else {
    cout << k + k / 2;
  }
}
