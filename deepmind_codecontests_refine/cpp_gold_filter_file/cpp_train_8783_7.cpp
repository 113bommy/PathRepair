#include <bits/stdc++.h>
using namespace std;
const int N = 1000000 + 10;
int d[N];
int n;
int st[N], top;
bool popStack(int key) {
  if (top <= 0) {
    return false;
  }
  while (top > 0 && d[st[top - 1]] != key) {
    int tmpKey = d[st[top - 1]];
    d[st[top - 1]] = -d[st[top - 1]];
    top--;
    if (!popStack(tmpKey)) {
      return false;
    }
  }
  if (top <= 0) {
    return false;
  }
  top--;
  return true;
}
bool ok() {
  for (int i = 1; i <= n; ++i) {
    if (d[i] < 0) {
      if (!popStack(-d[i])) {
        return false;
      }
    } else {
      st[top++] = i;
    }
  }
  while (top > 0) {
    int tmpKey = d[st[top - 1]];
    d[st[top - 1]] = -d[st[top - 1]];
    top--;
    if (!popStack(tmpKey)) {
      return false;
    }
  }
  return true;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &d[i]);
  }
  int negCount;
  cin >> negCount;
  while (negCount--) {
    int x;
    cin >> x;
    d[x] = -d[x];
  }
  if (!ok()) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
    for (int i = 1; i <= n; ++i) {
      printf("%d ", d[i]);
    }
  }
}
