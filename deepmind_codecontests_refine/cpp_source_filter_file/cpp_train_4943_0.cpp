#include <bits/stdc++.h>
using namespace std;
int m, n;
char buf[101011];
char s[11];
int ans[101010];
int main() {
  int curr = -1;
  char c;
  vector<int> fin;
  int f;
  while (1) {
    scanf(" %*[^<]");
    scanf(" <");
    scanf("%[^t]", s);
    scanf("%*c");
    if (scanf("%c", &c) == EOF) break;
    if (c == 'a') {
      if (s[0] == 0)
        curr++;
      else if (s[0] == '/') {
        fin.push_back(ans[curr]);
        ans[curr] = 0;
        curr--;
      }
    } else if (c == 'd') {
      if (s[0] == 0) ans[curr]++;
    }
    s[0] = 0;
  }
  sort(fin.begin(), fin.end());
  for (unsigned i = 0; i < fin.size(); i++) {
    printf("%d ", fin[i]);
  }
  puts("");
  return 0;
}
