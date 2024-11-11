#include <bits/stdc++.h>
using namespace std;
int main() {
  char first[100], second[100], third[100];
  gets(first);
  gets(second);
  gets(third);
  int siz1 = strlen(first);
  int siz2 = strlen(second);
  int siz3 = strlen(third);
  int vow1 = 0, vow2 = 0, vow3 = 0;
  for (int x = 0; x < siz1; x++) {
    if (first[x] == 'a' || first[x] == 'e' || first[x] == 'i' ||
        first[x] == 'o' || first[x] == 'u') {
      vow1++;
    }
  }
  for (int x = 0; x < siz2; x++) {
    if (second[x] == 'a' || second[x] == 'e' || second[x] == 'i' ||
        second[x] == 'o' || second[x] == 'u') {
      vow2++;
    }
  }
  for (int x = 0; x < siz3; x++) {
    if (third[x] == 'a' || third[x] == 'e' || third[x] == 'i' ||
        third[x] == 'o' || third[x] == 'u') {
      vow3++;
    }
  }
  if (vow1 == 5 && vow2 == 7 && vow3 == 5) {
    cout << "YES";
  } else {
    cout << "NO";
  }
}
