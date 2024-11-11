#include <bits/stdc++.h>
using namespace std;
string line;
int res = 0, mn = 0, my = 0, in;
stack<char> s;
char last;
int main() {
  cin >> line;
  for (int i = 0; i < line.length(); i++) {
    if (line[i] == '+')
      in++;
    else
      in--;
    if (in > 0) my = max(my, in);
    if (in < 0) mn = min(mn, in);
  }
  printf("%d\n", my + (-mn));
}
