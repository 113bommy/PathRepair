#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:20000000")
string problem_name = "a";
void init() { freopen((problem_name + ".in").c_str(), "rt", stdin); }
int main() {
  int n;
  scanf("%d", &n);
  printf("%d", n);
  for (int i = 2; i < n; i++) printf(" %d", i);
  return 0;
}
