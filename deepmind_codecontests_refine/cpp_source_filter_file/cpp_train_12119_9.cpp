#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  int data[n];
  int count = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", data + i);
    if (data[i] == i) count++;
  }
  bool found = false;
  for (int i = 0; i < n; i++) {
    if (data[i] != i) {
      if (data[data[i]] == i) {
        found = true;
        break;
      }
    }
  }
  if (found)
    count += 2;
  else
    count++;
  printf("%d\n", count);
  return 0;
}
