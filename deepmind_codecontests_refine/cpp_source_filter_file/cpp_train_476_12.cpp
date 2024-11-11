#include <bits/stdc++.h>
using namespace std;
int main() {
  int s, v1, v2, t1, t2;
  cin >> s >> v1 >> v2 >> t1 >> t2;
  int a1 = v1 * s + 3 * t1;
  int a2 = v2 * s + 2 * t2;
  if (a1 < a2)
    puts("First");
  else if (a1 > a2)
    puts("Second");
  else
    puts("Friendship");
  return 0;
}
