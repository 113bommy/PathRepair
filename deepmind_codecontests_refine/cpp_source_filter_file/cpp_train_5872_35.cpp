#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x;
  while (scanf("%d%d", &n, &x) != EOF) {
    if (n == 5) {
      puts(">...v");
      puts("v.<..");
      puts("..^..");
      puts(">....");
      puts("..^.<");
      puts("1 1");
    } else if (n == 3) {
      puts(">vv");
      puts("^<.");
      puts("^.<");
      puts("1 3");
    } else {
      for (int i = 0; i < 34; ++i) cout << ">";
      for (int i = 0; i < 32; ++i) cout << ".>";
      puts("v.");
      for (int i = 0; i < 49; ++i) {
        cout << "^>";
        for (int i = 0; i < 32; ++i) cout << "<.";
        for (int i = 0; i < 33; ++i) cout << "<";
        puts(".");
        cout << "^";
        for (int i = 0; i < 33; ++i) cout << ">";
        for (int i = 0; i < 32; ++i) cout << ".>";
        puts("v.");
      }
      cout << "^";
      for (int i = 0; i < 32; ++i) cout << "<.";
      for (int i = 0; i < 33; ++i) cout << "<";
      puts("<.");
      puts("1 1");
    }
  }
  return 0;
}
