#include <bits/stdc++.h>
using namespace std;
int main() {
  char passchar[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                       'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
                       's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
  char mypassword[100];
  int n, k, i, l, j, counter1, counter2, makesure;
  cin >> n >> k;
  if (n - k == 0) {
    for (i = 0; i < n; i++) {
      mypassword[i] = passchar[i];
    }
  } else {
    for (i = 0; i < k; i++) {
      mypassword[i] = passchar[i];
    }
    makesure = i;
    counter2 = n - k;
    for (j = 0, i = makesure; i < n; i++, j++) {
      if (j == k) j = 0;
      mypassword[i] = passchar[j];
    }
  }
  for (l = 0; l < n; l++) {
    cout << mypassword[l];
  }
  return 0;
}
