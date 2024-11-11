#include <bits/stdc++.h>
using namespace std;
char str[30], best[30];
int main() {
  scanf("%s", str);
  int size = strlen(str);
  int i = 0, j = size - 1, best = i;
  bool ok = true;
  vector<char> front;
  stack<char> back;
  while (true) {
    for (int k = i; k <= j; ++k) {
      if (str[k] >= str[best]) {
        ok = true;
        best = k;
      }
    }
    if (!ok) break;
    for (; i <= j; ++i) {
      if (str[i] == str[best]) break;
    }
    for (; j >= i; --j) {
      if (str[j] == str[best]) break;
    }
    if (i != j) {
      front.push_back(str[i]);
      back.push(str[j]);
      ++i;
      --j;
    } else {
      front.push_back(str[i]);
      ++i;
    }
    ok = false;
  }
  for (int z = 0; z < front.size(); ++z) printf("%c", front[z]);
  while (!back.empty()) {
    printf("%c", back.top());
    back.pop();
  }
  printf("\n");
  return 0;
}
