#include <bits/stdc++.h>
using namespace std;
int main() {
  int num, time;
  char student[100];
  scanf("%d %d", &num, &time);
  scanf("%s", student);
  while (time--) {
    for (int i = 0; i < strlen(student) - 1; i++) {
      if (student[i] == 'B' && student[i + 1] == 'G') {
        swap(student[i], student[i + 1]);
        i = i + 2;
      }
    }
  }
  printf("%s\n", student);
  return 0;
}
