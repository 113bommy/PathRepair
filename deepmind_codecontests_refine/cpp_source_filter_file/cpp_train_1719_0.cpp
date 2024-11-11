#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000005;
int num[MAXN], leftBracket[MAXN];
int main() {
  string str;
  cin >> str;
  int count = 0, max = 0, times = 0;
  for (int i = 0; i < str.size(); ++i) {
    if (str[i] == '(')
      leftBracket[++count] = i;
    else if (count) {
      int pairLeft = leftBracket[count];
      num[i] = i - pairLeft + 1 + num[pairLeft - 1];
      --count;
      if (num[i] == max) {
        ++times;
      } else if (num[i] > max) {
        max = num[i];
        times = 1;
      }
    }
  }
  printf("%d %d\n", max, times);
  return 0;
}
