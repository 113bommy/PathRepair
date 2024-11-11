#include <bits/stdc++.h>
int main() {
  char day1[10], day2[10];
  int first, second;
  scanf("%s %s", day1, day2);
  if (strstr(day1, "monday")) first = 1;
  if (strstr(day1, "tuesday")) first = 2;
  if (strstr(day1, "wednesday")) first = 3;
  if (strstr(day1, "thursday")) first = 4;
  if (strstr(day1, "friday")) first = 5;
  if (strstr(day1, "saturday")) first = 6;
  if (strstr(day1, "sunday")) first = 7;
  if (strstr(day2, "monday")) second = 1;
  if (strstr(day2, "tuesday")) second = 2;
  if (strstr(day2, "wednesday")) second = 3;
  if (strstr(day2, "thursday")) second = 4;
  if (strstr(day2, "friday")) second = 5;
  if (strstr(day2, "saturday")) second = 6;
  if (strstr(day2, "sunday")) second = 7;
  if (second >= first) {
    if ((second - first) == 1 || (second - first) > 3)
      printf("NO");
    else {
      printf("YES");
    }
  } else {
    if ((first - second == 4) || (first - second == 5))
      printf("YES");
    else {
      printf("NO");
    }
  }
  return 0;
}
