#include <bits/stdc++.h>
using namespace std;
int val[200];
int main() {
  string linha;
  int pos;
  char letras[100002];
  cin >> linha;
  memset(val, 0, sizeof(val));
  for (int i = 0; i < linha.size(); i++) {
    int v = (int)linha[i];
    val[v]++;
    for (int j = v - 1; j >= 'a'; j--) {
      val[j] = 0;
    }
  }
  pos = 0;
  for (int i = 'z'; i >= 'a'; i--) {
    if (val[i]) {
      while (val[i]--) {
        letras[pos++] = i;
      }
    }
  }
  letras[pos++] = 10;
  printf("%s", letras);
  return 0;
}
