#include <bits/stdc++.h>
using namespace std;
struct InputModel {
  int number, index;
};
struct CheckModel {
  int max, leave;
};
bool MySort(InputModel a, InputModel b);
int n, output;
InputModel input[100000];
CheckModel check;
int main(int argc, char** argv) {
  int i, j, k;
  output = 0;
  scanf(" %d", &n);
  for (i = 0; i < n; i++) {
    scanf(" %d", &input[i].number);
    input[i].index = i + 1;
  }
  sort(input, input + n, MySort);
  check.max = input[0].index;
  check.leave = input[0].index;
  for (i = 0; i < n; i++) {
    if (input[i].index > check.max) {
      check.leave = input[i].index - check.max - 1;
      check.max = input[i].index;
    } else {
      check.leave--;
    }
    if (check.leave == 0) {
      output++;
    }
  }
  printf("%d\n", output);
  return 0;
}
bool MySort(InputModel a, InputModel b) {
  int i, j, k;
  if (a.number == b.number) {
    return a.index < b.index;
  } else {
    return a.number < b.number;
  }
}
