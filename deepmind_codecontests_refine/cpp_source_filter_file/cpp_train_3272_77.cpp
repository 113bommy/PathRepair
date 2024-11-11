#include <bits/stdc++.h>
using namespace std;
int main() {
  int columns, i;
  scanf("%d \n", &columns);
  int array[columns], temp[columns];
  temp[0] = 0;
  for (i = 0; i < columns; i++) {
    scanf("%d", &array[i]);
  }
  sort(array, array + columns);
  for (i = 0; i < columns; i++) {
    printf("%d", array[i]);
  }
  return 0;
}
