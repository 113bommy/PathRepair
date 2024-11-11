#include <bits/stdc++.h>
using namespace std;
int h, m;
int main() {
  scanf("%d:%d", &h, &m);
  if (h == 00) {
    printf("01:10");
  }
  if (h == 01) {
    if (m < 10)
      printf("01:10");
    else
      printf("02:20");
  }
  if (h == 02) {
    if (m < 20)
      printf("02:20");
    else
      printf("03:30");
  }
  if (h == 03) {
    if (m < 30)
      printf("03:30");
    else
      printf("04:40");
  }
  if (h == 04) {
    if (m < 40)
      printf("04:40");
    else
      printf("05:50");
  }
  if (h == 05) {
    if (m < 50)
      printf("05:50");
    else
      printf("10:01");
  }
  if (h > 5 && h < 10) {
    printf("10:01");
  }
  if (h == 10) {
    if (m < 1)
      printf("10:01");
    else
      printf("11:11");
  }
  if (h == 11) {
    if (m < 11)
      printf("11:11");
    else
      printf("12:21");
  }
  if (h == 12) {
    if (m < 21)
      printf("12:21");
    else
      printf("13:31");
  }
  if (h == 13) {
    if (m < 31)
      printf("13:31");
    else
      printf("14:41");
  }
  if (h == 14) {
    if (m < 41)
      printf("14:41");
    else
      printf("15:51");
  }
  if (h == 15) {
    if (m < 51)
      printf("15:51");
    else
      printf("20:02");
  }
  if (h > 16 && h < 20) {
    printf("20:02");
  }
  if (h == 20) {
    if (m < 02)
      printf("20:02");
    else
      printf("21:12");
  }
  if (h == 21) {
    if (m < 12)
      printf("21:12");
    else
      printf("22:22");
  }
  if (h == 22) {
    if (m < 22)
      printf("22:22");
    else
      printf("23:32");
  }
  if (h == 23) {
    if (m < 32)
      printf("23:32");
    else
      printf("00:00");
  }
}
