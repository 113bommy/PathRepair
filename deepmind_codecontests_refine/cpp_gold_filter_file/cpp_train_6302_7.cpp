#include <bits/stdc++.h>
using namespace std;
string s1;
char ans_t[1000 + 10];
string fun(int tar) {
  stringstream ss;
  ss << tar;
  return ss.str();
}
int main() {
  int n;
  for (int i = 1; i <= 400; i++) {
    s1 += fun(i);
  }
  while (scanf("%d", &n) != EOF) {
    cout << s1[n - 1] << endl;
  }
  return 0;
}
