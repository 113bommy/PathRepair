#include <bits/stdc++.h>
using namespace std;
inline int quan(char* str, char symb) {
  int c = 0;
  for (int i = 0; i < strlen(str); i++)
    if (str[i] == symb) c++;
  return c;
}
struct command {
  int pos;
  char ch;
};
int compare(const void* a, const void* b) { return (*(int*)a - *(int*)b); }
int main() {
  int k, n, count = 0, x, y;
  char str[101];
  cin >> k >> str >> n;
  command* mass = new command[n];
  int* positions = new int[n];
  for (int i = 0; i < n; i++) {
    cin >> mass[i].pos >> mass[i].ch;
    for (int j = 0; j < i; j++)
      if (mass[i].ch == mass[j].ch)
        if (mass[i].pos >= mass[j].pos) mass[i].pos++;
    int q = quan(str, mass[i].ch);
    int y = mass[i].pos % q;
    int x = mass[i].pos / q;
    if (y == 0) {
      y = q;
      x--;
    }
    for (int m = 0; m < strlen(str); m++) {
      if (str[m] == mass[i].ch) count++;
      if (count == y) {
        count = 0;
        positions[i] = ((x)*strlen(str)) + m;
        break;
      }
    }
    for (int v = 0; v < i; v++)
      if (mass[i].pos < mass[v].pos) {
        command temp = mass[i];
        for (int w = i - 1; w >= v; w--) mass[w + 1] = mass[w];
        mass[v] = temp;
        break;
      }
  }
  qsort(positions, n, sizeof(int), compare);
  count = 0;
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < strlen(str); j++) {
      if (positions[count] != (i)*strlen(str) + j)
        cout << str[j];
      else
        count++;
    }
  }
  return 0;
}
