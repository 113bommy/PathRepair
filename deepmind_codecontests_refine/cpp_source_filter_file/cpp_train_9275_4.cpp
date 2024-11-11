#include <bits/stdc++.h>
using namespace std;
int n;
int* a;
char* s;
vector<int>* v;
bool* vis;
char pob(int i) {
  if (v[i].size() == 0) {
    return 'B';
  } else {
    for (int j = 0; j < v[i].size(); j++) {
      if (s[v[i][j] - 1] == 'B') return 'A';
    }
    return 'B';
  }
}
int main() {
  scanf("%d", &n);
  a = new int[n + 3];
  s = new char[n];
  v = new vector<int>[n + 3];
  vis = new bool[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j += a[i]) {
      if ((j - i) % a[i] == 0 && a[j] > a[i]) v[a[i]].push_back(a[j]);
    }
    for (int j = 0; j < i; j += a[i]) {
      if ((i - j) % a[i] == 0 && a[j] > a[i]) v[a[i]].push_back(a[j]);
    }
  }
  for (int i = n; i > 0; i--) {
    s[i - 1] = pob(i);
  }
  for (int i = 0; i < n; i++) {
    printf("%c", s[a[i] - 1]);
  }
  return 0;
}
