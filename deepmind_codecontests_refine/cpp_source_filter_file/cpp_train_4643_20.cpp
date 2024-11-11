#include <bits/stdc++.h>
using namespace std;
char s[100001], an[100001], mn[100001];
int main() {
  scanf("%s", s);
  int n = strlen(s);
  mn[n] = 'z' + 1;
  for (int i = n - 1; i >= 0; --i) mn[i] = min(mn[i + 1], s[i]);
  stack<char> st;
  int j = 0;
  for (int i = 0; i < (int)(n); ++i) {
    st.push(s[i]);
    while (!st.empty() && st.top() < mn[i + 1]) an[j++] = st.top(), st.pop();
  }
  printf("%s\n", an);
}
