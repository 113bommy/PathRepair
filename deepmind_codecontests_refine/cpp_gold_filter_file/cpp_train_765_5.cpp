#include <bits/stdc++.h>
using namespace std;
int N;
char s[20 + 10];
string A[30 + 10], ans;
bool sol;
int main() {
  scanf("%d", &N);
  gets(s);
  for (int i = 0; i < N; i++) {
    gets(s);
    A[i] = s;
  }
  ans = "a";
  while (true) {
    sol = true;
    for (int i = 0; i < N; i++)
      if (A[i].find(ans) != string::npos) sol = false;
    if (sol) break;
    ans[ans.length() - 1]++;
    for (int i = ans.length() - 1; i >= 1; i--) {
      if (ans[i] > 'z') {
        ans[i] = 'a';
        ans[i - 1]++;
      }
    }
    if (ans[0] > 'z') {
      ans[0] = 'a';
      ans.push_back('a');
    }
  }
  printf("%s\n", ans.c_str());
}
