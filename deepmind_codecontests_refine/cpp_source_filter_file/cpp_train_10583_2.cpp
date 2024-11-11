#include <bits/stdc++.h>
using namespace std;
char ch[100][101];
char word[200];
bool used[200];
char letter;
int len;
char tolower(char ch) {
  if (ch >= 'a' && ch <= 'z') {
    return ch;
  } else {
    return (char)(ch - ('A' - 'a'));
  }
}
bool isLower(char ch) { return ch >= 'a' && ch <= 'z'; }
void printHelp(bool lowerCase, char ch) {
  char help;
  if (isLower(ch)) {
    help = ch;
  } else {
    help = tolower(ch);
  }
  if (lowerCase) {
    printf("%c", help);
  } else {
    printf("%c", help + ('A' - 'a'));
  }
}
int main() {
  int N;
  scanf("%d", &N);
  ;
  for (int(n) = 0; n < (int)N; n++) {
    scanf("%s", ch[n]);
    ;
  }
  scanf("%s\n", word);
  len = strlen(word);
  memset(used, false, sizeof(used));
  scanf("%c", &letter);
  for (int(n) = 0; n < (int)N; n++) {
    int len2 = strlen(ch[n]);
    for (int m = 0; m + len2 <= len; m++) {
      if (tolower(ch[n][0]) == tolower(word[m])) {
        bool compare = true;
        for (int k = 0; k < len2; k++) {
          if (tolower(ch[n][k]) != tolower(word[m + k])) {
            compare = false;
            break;
          };
        }
        if (compare) {
          for (int(k) = 0; k < (int)len2; k++) {
            used[m + k] = true;
          }
        }
      }
    }
  }
  for (int(n) = 0; n < (int)len; n++) {
    if (used[n]) {
      if (tolower(word[n]) == tolower(letter)) {
        if (isLower(letter) == 'a') {
          printHelp(isLower(word[n]), 'b');
        } else {
          printHelp(isLower(word[n]), 'a');
        }
      } else {
        printHelp(isLower(word[n]), letter);
      }
    } else {
      printHelp(isLower(word[n]), word[n]);
    }
  }
  printf("\n");
}
