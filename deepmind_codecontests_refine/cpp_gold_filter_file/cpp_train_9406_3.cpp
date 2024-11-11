#include <bits/stdc++.h>
using namespace std;
char s[100001];
bool o[100001];
vector<int> v;
int main() {
  scanf("%s", s);
  int l = strlen(s);
  for (int i = l - 1; i > -1; --i) {
    if (s[i] == ')' || s[i] == ']')
      v.push_back(i);
    else if (v.empty() || s[i] == '(' && s[v[v.size() - 1]] != ')' ||
             s[i] == '[' && s[v[v.size() - 1]] != ']')
      v.clear();
    else {
      o[i] = true;
      o[v[v.size() - 1]] = true;
      v.pop_back();
    }
  }
  int b = 0;
  int bI = 0;
  int c = 0;
  int cI = 0;
  for (int i = 0; i < l; ++i) {
    if (!o[i]) {
      if (c > b) {
        b = c;
        bI = cI;
      }
      cI = i + 1;
      c = 0;
    } else if (s[i] == ']')
      c++;
  }
  if (c > b) {
    b = c;
    bI = cI;
  }
  printf("%d\n", b);
  for (int i = bI; o[i]; ++i) {
    printf("%c", s[i]);
    if (s[i] == ']') b--;
  }
  printf("\n");
  return 0;
}
