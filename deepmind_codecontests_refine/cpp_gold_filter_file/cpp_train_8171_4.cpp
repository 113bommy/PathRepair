#include <bits/stdc++.h>
using namespace std;
int n;
int arr[300006];
int marc[300006];
int e[300006][4];
int a, b, c;
int k;
int pos[300006];
int mayor = -1;
bool capitan(int x) {
  for (int i = 1; i < pos[x]; i++) {
    if (marc[i] == false) {
      return false;
    }
  }
  return true;
}
int main() {
  scanf("%d", &n);
  priority_queue<int> cola;
  for (int i = 1; i <= 3 * n; i++) {
    scanf("%d", &arr[i]);
    pos[arr[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d %d %d", &e[i][0], &e[i][1], &e[i][2]);
  }
  scanf("%d", &k);
  bool enc = false;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 3; j++) {
      if (e[i][j] == k) {
        enc = true;
      }
    }
    if (enc) {
      if (capitan(k)) {
        for (int j = 0; j < 3; j++) {
          if (e[i][j] != k) {
            marc[pos[e[i][j]]] = true;
            mayor = max(mayor, e[i][j]);
          }
        }
        for (int i = 1; i <= 3 * n; i++) {
          if (arr[i] != k) {
            if (marc[i] && arr[i] <= mayor) {
              cola.push(-arr[i] + 1000000);
            } else {
              cola.push(-arr[i]);
            }
          }
        }
      } else {
        for (int i = 1; i <= 3 * n; i++) {
          if (i != k) {
            cola.push(-i);
          }
        }
      }
      break;
    } else {
      for (int j = 0; j < 3; j++) {
        marc[pos[e[i][j]]] = true;
      }
    }
  }
  int as;
  if (cola.top() >= 300006) {
    as = cola.top() - 1000000;
  } else {
    as = cola.top();
  }
  printf("%d", -as);
  cola.pop();
  while (!cola.empty()) {
    if (cola.top() >= 300006) {
      as = cola.top() - 1000000;
    } else {
      as = cola.top();
    }
    printf(" %d", -as);
    cola.pop();
  }
  return 0;
}
