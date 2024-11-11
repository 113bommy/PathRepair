#include <bits/stdc++.h>
using namespace std;
bool debug = false;
int n, m, k;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
long long ln, lk, lm;
int main() {
  scanf("%d%d", &n, &m);
  if (n == 5) {
    puts(">...v");
    puts("v.<..");
    puts("..^..");
    puts(">....");
    puts("..^.<");
  } else if (n == 3) {
    puts(">vv");
    puts("^<.");
    puts("^.<");
  } else {
    puts(
        "v<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<<<<<<<<<<<<<<<<<<<"
        "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<");
    puts(
        "v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>"
        "v>v>v>v>v>v>v>v>v>v>v>v>v>v>v^");
    for (int(i) = 0; (i) < (int)(24); (i)++) {
      puts(
          "v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v."
          "v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.");
      puts(
          "v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^"
          "v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^");
    }
    for (int(i) = 0; (i) < (int)(24); (i)++) {
      puts(
          "v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^"
          "v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^");
      puts(
          ".^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^"
          ".^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^");
    }
    puts(
        ">^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^"
        ">^>^>^>^>^>^>^>^>^>^>^>^>^>^>^");
    puts(
        "......................................................................"
        "..............................");
  }
  puts("1 1");
  return 0;
}
