#include <bits/stdc++.h>
int main() {
  char* v = NULL;
  int n = 0;
  char ch;
  do {
    ch = getchar();
    if (n == 0 && ch == '\n') {
      continue;
    }
    if (ch == '\n' || ch == EOF) {
      break;
    }
    ++n;
    v = (char*)realloc(v, sizeof(char) * n);
    v[n - 1] = ch;
  } while (1);
  int a;
  scanf("%d", &a);
  int h;
  if (v[0] == 'J' && v[n - 1] == 'y') {
    h = 1;
  }
  if (v[0] == 'F') {
    h = 2;
  }
  if (v[0] == 'M' && v[n - 1] == 'h') {
    h = 3;
  }
  if (v[0] == 'A' && v[n - 1] == 'l') {
    h = 4;
  }
  if (v[0] == 'M' && n == 3) {
    h = 5;
  }
  if (v[0] == 'J' && v[n - 1] == 'e') {
    h = 6;
  }
  if (v[0] == 'J' && v[n - 1] == 'y' && v[1] == 'u') {
    h = 7;
  }
  if (v[0] == 'A' && v[n - 1] == 't') {
    h = 8;
  }
  if (v[0] == 'S') {
    h = 9;
  }
  if (v[0] == 'O' && v[n - 1] == 'r') {
    h = 10;
  }
  if (v[0] == 'N') {
    h = 11;
  }
  if (v[0] == 'D') {
    h = 12;
  }
  int e = ((h - 1 + a) % 12) + 1;
  if (e == 1) {
    printf("January");
  }
  if (e == 2) {
    printf("February");
  }
  if (e == 3) {
    printf("March");
  }
  if (e == 4) {
    printf("April");
  }
  if (e == 5) {
    printf("May");
  }
  if (e == 6) {
    printf("June");
  }
  if (e == 7) {
    printf("July");
  }
  if (e == 8) {
    printf("August");
  }
  if (e == 9) {
    printf("September");
  }
  if (e == 10) {
    printf("October");
  }
  if (e == 11) {
    printf("November");
  }
  if (e == 12) {
    printf("December");
  }
}
