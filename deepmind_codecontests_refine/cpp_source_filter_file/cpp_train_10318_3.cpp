#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[100];
  int freq[101] = {};
  bool targee3 = 0;
  int u = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    freq[a[i]]++;
    if (freq[a[i]] == 1)
      u++;
    else if (freq[a[i]] == 2)
      u--;
    else
      targee3 = 1;
  }
  if (u % 2) {
    if (!targee3) {
      printf("NO");
      return 0;
    }
  } else
    targee3 = false;
  bool A = true;
  printf("YES\n");
  for (int i = 0; i < n; i++) {
    if (freq[a[i]] == 1) {
      if (A)
        printf("A");
      else
        printf("B");
      A = !A;
    } else if (freq[a[i]] == 2) {
      printf("A");
    } else if (targee3) {
      printf("B\n");
      targee3 = false;
    } else {
      printf("A");
    }
  }
  return 0;
}
