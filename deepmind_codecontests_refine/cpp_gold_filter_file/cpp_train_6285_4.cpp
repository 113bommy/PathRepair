#include <bits/stdc++.h>
using namespace std;
int main() {
  int top = 0, sum = 0;
  string a;
  cin >> a;
  for (int i = 0; i < a.size(); i++) {
    if (a[i] == '(') top++;
    if (a[i] == ')') {
      if (top > 0) sum += 2, top--;
    }
  }
  cout << sum;
  return 0;
}
