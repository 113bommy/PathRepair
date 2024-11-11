#include <bits/stdc++.h>
using namespace std;
char s[110], saux[110];
int Nr = 0, poz;
int main() {
  cin.getline(s, 105);
  strcpy(saux, s);
  while (strstr(saux, "Danil") != NULL) {
    Nr++;
    poz = strstr(saux, "Danil") - saux;
    strcpy(saux, saux + poz + 5);
  }
  strcpy(saux, s);
  while (strstr(saux, "Olya") != NULL) {
    Nr++;
    poz = strstr(saux, "Olya") - saux;
    strcpy(saux, saux + poz + 4);
  }
  strcpy(saux, s);
  while (strstr(saux, "Slava") != NULL) {
    Nr++;
    poz = strstr(saux, "Slava") - saux;
    strcpy(saux, saux + poz + 5);
  }
  strcpy(saux, s);
  while (strstr(saux, "Ann") != NULL) {
    Nr++;
    poz = strstr(saux, "Ann") - saux;
    strcpy(saux, saux + poz + 3);
  }
  strcpy(saux, s);
  while (strstr(saux, "Nikita") != NULL) {
    Nr++;
    poz = strstr(saux, "Nikita") - saux;
    strcpy(saux, saux + poz + 6);
  }
  if (Nr != 1)
    cout << "NO";
  else
    cout << "YES";
  return 0;
}
