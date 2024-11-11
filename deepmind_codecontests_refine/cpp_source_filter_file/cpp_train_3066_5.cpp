#include <bits/stdc++.h>
using namespace std;
int main() {
  char str[10];
  set<string> name;
  string ofcol;
  int n, i;
  scanf("%d\n", &n);
  for (i = 0; i < n; i++) {
    scanf("%s", str);
    ofcol = str;
    scanf("%s", str);
    ofcol += '1';
    ofcol += str;
    name.insert(ofcol);
  }
  printf("%d\n", name.size());
}
