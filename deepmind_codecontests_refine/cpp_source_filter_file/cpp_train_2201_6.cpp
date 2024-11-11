#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  char hi, hi1;
  int hh, hh1, mm, mm1, sum;
  scanf("%d%c%d", &hh, &hi, &mm);
  scanf("%d%c%d", &hh1, &hi1, &mm1);
  if (mm1 >= mm) {
    sum = (((hh1 - hh) * 60) + (mm1 - mm)) / 2;
  } else {
    sum = (((hh1 - hh) * 60) + (mm + mm1)) / 2;
  }
  int final_hh = sum / 60;
  int final_mm = (sum % 60);
  if (final_mm + mm >= 60 and mm1 >= mm) {
    final_hh = ((final_mm + mm) / 60) + final_hh;
    final_mm = (final_mm + mm) % 60;
  } else if (final_mm + mm < 60 and mm1 >= mm) {
    final_mm = (final_mm + mm);
    final_hh = final_hh + hh;
  } else {
    final_mm = final_mm;
    final_hh = final_hh + hh;
  }
  if (final_hh < 10 and final_mm < 10) {
    printf("0%d:0%d", final_hh, final_mm);
  } else if (final_hh < 10 and final_mm >= 10) {
    printf("0%d:%d", final_hh, final_mm);
  } else if (final_hh >= 10 and final_mm < 10) {
    printf("%d:0%d", final_hh, final_mm);
  } else {
    printf("%d:%d", final_hh, final_mm);
  }
}
