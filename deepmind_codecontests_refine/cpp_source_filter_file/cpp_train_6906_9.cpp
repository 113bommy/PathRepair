#include <bits/stdc++.h>
using namespace std;
char word[2000000];
string aux;
bool amp;
int main() {
  amp = false;
  while (fgets(word, 2000000, stdin)) {
    int n = strlen(word);
    int ind = 0;
    while (word[ind] == ' ') ind++;
    if (word[ind] == '#') {
      if (amp) {
        printf("\n");
        amp = false;
      }
      printf("%s", word);
    } else {
      amp = true;
      for (int i = 0; i < n; i++)
        if (word[i] != ' ' && word[i] != '\n') printf("%c", word[i]);
    }
  }
  printf("\n");
  return 0;
}
