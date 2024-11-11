#include <bits/stdc++.h>
#pragma comment(linker, "/stack:32000000")
using namespace std;
const int INF = 2147483647;
const long long LLINF = 9223372036854775807LL;
int main() {
  int n;
  scanf("%d", &n);
  if (n == 5)
    printf(">...v\nv.<..\n..^..\n>....\n..^.<\n1 1\n");
  else if (n == 3)
    printf(">vv\n^<.\n^.<\n1 3\n");
  else {
    string s1 = "v ";
    int c1 = 32;
    int c2 = 34;
    for (int i = 0; i < c1; ++i) s1 += "< ";
    for (int i = 0; i < c2; ++i) s1 += "<";
    string s2 = "";
    for (int i = 0; i < c2; ++i) s2 += ">";
    for (int i = 0; i < c1; ++i) s2 += " >";
    s2 += " ^";
    for (int i = 0; i < 100; ++i) {
      if (i % 2 == 0)
        cout << s1 << "\n";
      else
        cout << s2 << "\n";
    }
    cout << 100 << " " << 100 << "\n";
  }
  return 0;
}
