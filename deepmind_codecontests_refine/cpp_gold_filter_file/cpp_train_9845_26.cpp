#include <bits/stdc++.h>
char let;
int n, t, contA, contD;
using namespace std;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf(" %c", &let);
    if (let == 'A') {
      contA++;
    } else {
      contD++;
    }
  }
  if (contA == contD) {
    printf("Friendship");
  }
  if (contA < contD) {
    printf("Danik");
  }
  if (contA > contD) {
    printf("Anton");
  }
  return 0;
}
