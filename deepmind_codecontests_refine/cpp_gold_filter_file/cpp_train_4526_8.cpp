#include <bits/stdc++.h>
using namespace std;
char s[100005];
int sz, a[100005], t;
vector<int> v, o;
int main() {
  gets(s + 1);
  int sz = strlen(s + 1);
  t = 1;
  for (int i = 1; i <= sz; i++) {
    if (s[i] == '(')
      a[i] = a[i - 1] + 1;
    else if (s[i] == ')')
      a[i] = a[i - 1] - 1;
    else {
      t = i;
      v.push_back(1);
      a[i] = a[i - 1] - 1;
    }
  }
  for (int i = 1; i <= sz; i++)
    if (a[i] < 0) {
      puts("-1");
      return 0;
    }
  int p = 0, q = 0;
  for (int i = t + 1; i <= sz; i++) {
    if (s[i] == '(')
      o.push_back(i);
    else if (o.size() > 0)
      o.pop_back();
  }
  if (o.size() > 0) {
    puts("-1");
    return 0;
  }
  if (a[sz] > 0) {
    v[v.size() - 1] += a[sz];
  }
  for (int i = 0; i < v.size(); i++) cout << v[i] << endl;
  return 0;
}
