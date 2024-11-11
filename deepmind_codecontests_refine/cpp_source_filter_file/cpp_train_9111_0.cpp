#include <bits/stdc++.h>
using namespace std;
const int N = 1000010;
bool composite[2 * N];
int has[N];
int n;
vector<int> v;
int main() {
  for (int i = 2; i * i < 2 * N; i++) {
    if (!composite[i]) {
      for (int j = i * i; j < 2 * N; j += i) {
        composite[j] = true;
      }
    }
  }
  vector<int> ans;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    if (!has[x]) {
      v.push_back(x);
    }
    has[x]++;
  }
  if (has[1] > 1) {
    for (int i = 0; i < has[1]; i++) ans.push_back(1);
    bool ok = false;
    for (int i = 0; i < v.size(); i++) {
      if (v[i] == 1) continue;
      if (!composite[v[i] + 1]) {
        ans.push_back(v[i]);
        ok = true;
      }
    }
  } else {
    bool ok = false;
    for (int i = 0; i < v.size() and !ok; i++) {
      for (int j = i + 1; j < v.size() and !ok; j++) {
        if (!composite[v[i] + v[j]]) {
          ans.push_back(v[i]);
          ans.push_back(v[j]);
          ok = true;
        }
      }
    }
    if (!ok) ans.push_back(v[0]);
  }
  printf("%d\n", (int)ans.size());
  for (int i = 0; i < ans.size(); i++) {
    if (i) printf(" ");
    printf("%d", ans[i]);
  }
  printf("\n");
  return 0;
}
