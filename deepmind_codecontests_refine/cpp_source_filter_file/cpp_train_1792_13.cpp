#include <bits/stdc++.h>
using namespace std;
ifstream fin("date.in");
int poz, lungS, suma, rasp;
char s[300050], caracter, caracterSt, caracterDr;
bool Cauta(int in, int sf) {
  if (in == -1 && sf == lungS) return true;
  if (in == -1 || sf == lungS) return false;
  caracterSt = s[in];
  caracterDr = s[sf];
  if (caracterSt == caracterDr) {
    int inNou = in;
    int sfNou = sf;
    while (s[inNou - 1] == caracterDr) {
      inNou--;
      if (inNou == 0) break;
    }
    while (s[sfNou + 1] == caracterSt) {
      sfNou++;
      if (sfNou == lungS) break;
    }
    if (in - inNou + 1 + sfNou - sf + 1 >= 3) {
      return Cauta(inNou - 1, sfNou + 1);
    } else {
      return false;
    }
  } else {
    return false;
  }
}
int main() {
  fin.getline(s, 300000);
  lungS = strlen(s);
  char ant = '1';
  int cate = 0;
  for (int i = 0; i < lungS; i++) {
    if (ant != s[i]) cate++;
    ant = s[i];
  }
  if (cate % 2 == 0)
    cout << 0;
  else {
    bool found = false;
    int cur = 0;
    int stop = cate / 2 + 1;
    int in = 0;
    ant = '1';
    while (cur < stop) {
      if (ant != s[in]) cur++;
      ant = s[in];
      in++;
    }
    in--;
    caracter = s[in];
    int sf = in;
    while (s[++sf] == caracter) {
    }
    if (sf - in >= 2)
      if (Cauta(in - 1, sf)) {
        cout << sf - in + 1;
        return 0;
      }
    cout << 0;
  }
  return 0;
}
