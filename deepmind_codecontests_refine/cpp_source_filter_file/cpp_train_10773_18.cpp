#include <bits/stdc++.h>
using namespace std;
const int sz = 1000006;
char in[5003];
int len, pos[20], mul;
stack<long long> stk;
stack<char> stk2;
long long maxi;
long long max(long long a, long long b) { return (a > b) ? a : b; }
void cal(int a, int b) {
  long long tmp = 0;
  long long t;
  int i;
  for (i = pos[a] + 1; i < pos[b]; i += 2) {
    if (!stk2.empty()) {
      stk2.pop();
      t = stk.top(), stk.pop();
      stk.push(t * (in[i] - '0'));
      while (!stk2.empty()) stk2.pop();
    } else {
      stk.push(in[i] - '0');
    }
    if (in[i + 1] == '*') stk2.push(in[i + 1]);
  }
  while (!stk2.empty()) stk2.pop();
  while (!stk.empty()) {
    tmp += stk.top();
    stk.pop();
  }
  for (i = 0; i < len;) {
    if (i == pos[a] + 1) {
      if (i != 0) {
        t = stk.top(), stk.pop();
        stk.push(t * tmp);
        stk2.push('*');
      } else {
        stk.push(tmp);
        stk2.push('*');
      }
      i = pos[b] + 1;
    } else {
      if (!stk2.empty()) {
        stk2.pop();
        t = stk.top(), stk.pop();
        stk.push(t * (in[i] - '0'));
        while (!stk2.empty()) stk2.pop();
      } else
        stk.push(in[i] - '0');
      if (in[i + 1] == '*' && (i + 1) != a) stk2.push('*');
      i += 2;
    }
  }
  while (!stk2.empty()) stk2.pop();
  tmp = 0;
  while (!stk.empty()) {
    tmp += stk.top();
    stk.pop();
  }
  if (tmp > maxi) maxi = tmp;
}
int main() {
  int i, j, k;
  pos[0] = -1;
  while (scanf("%s", in) != EOF) {
    maxi = 0;
    len = strlen(in);
    mul = 1;
    for (i = 1; i < len; i += 2) {
      if (in[i] == '*') pos[mul++] = i;
    }
    pos[mul++] = len;
    for (i = 0; i < mul; i++) {
      for (j = i + 1; j < mul; j++) {
        cal(i, j);
      }
    }
    printf("%lld\n", maxi);
  }
  return 0;
}
