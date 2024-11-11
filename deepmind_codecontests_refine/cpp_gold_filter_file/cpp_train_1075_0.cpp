#include <bits/stdc++.h>
using namespace std;
int jumpn(int i, int j, int n) {
  int count = 1;
  int s1 = j - i;
  int s2 = n - i;
  while (1) {
    if (s1 == 0) {
      return count;
    }
    int Ls1 = (int)(log(s1) / log(2));
    int Ls2 = (int)(log(s2) / log(2));
    if (Ls1 != Ls2) {
      return count;
    } else {
      s1 = s1 - pow(2, Ls1);
      s2 = s2 - pow(2, Ls1);
      count++;
    }
  }
}
int main() {
  int n;
  cin >> n;
  int a[100000];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int j = 1; j < n; j++) {
    long S = 0;
    for (int i = 1; i < j + 1; i++) {
      S = S + a[i - 1] * jumpn(i, j, n);
    }
    cout << S << endl;
  }
  return 0;
}
