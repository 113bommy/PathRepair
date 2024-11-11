#include <bits/stdc++.h>
using namespace std;
const int mn = 1100000;
struct node {
  char a;
  int viz;
  bool operator<(const node x) const {
    if (x.a < a)
      return 1;
    else if (x.a == a && viz < x.viz)
      return 1;
    return 0;
  }
} test[mn];
char s[mn];
int main() {
  while (scanf("%s", s) != EOF) {
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
      test[i].a = s[i];
      test[i].viz = i;
    }
    sort(test, test + len - 1);
    int x = -1;
    for (int i = 0; i < len; i++) {
      if (x < test[i].viz) {
        x = test[i].viz;
        printf("%c", test[i].a);
      }
    }
    puts("");
  }
}
