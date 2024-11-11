#include <bits/stdc++.h>
using namespace std;
string s;
int main() {
  stringstream ss;
  for (int i = 1; i <= 200; i++) ss << i;
  ss >> s;
  int n;
  scanf("%d", &n);
  printf("%c\n", s[n - 1]);
  return 0;
}
