#include <bits/stdc++.h>
using namespace std;
typedef struct {
  int pos;
  int num;
} appletree;
appletree plusland[123];
appletree minusland[123];
int main() {
  int n;
  int siz;
  int answer = 0;
  appletree temp;
  int nplus = 0;
  int nminus = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> temp.pos >> temp.num;
    if (temp.pos > 0) {
      plusland[nplus] = temp;
      nplus++;
    } else {
      minusland[nminus] = temp;
      nminus++;
    }
  }
  for (int i = 0; i < nplus - 1; i++) {
    for (int j = i + 1; j < nplus; j++) {
      if (abs(plusland[i].pos) > abs(plusland[j].pos)) {
        temp = plusland[i];
        plusland[i] = plusland[j];
        plusland[j] = temp;
      }
    }
  }
  for (int i = 0; i < nminus - 1; i++) {
    for (int j = i + 1; j < nminus; j++) {
      if (abs(minusland[i].pos) > abs(minusland[j].pos)) {
        temp = minusland[i];
        minusland[i] = minusland[j];
        minusland[j] = temp;
      }
    }
  }
  siz = min(nplus, nminus);
  if (siz == nplus) {
    for (int i = 0; i < siz; i++) {
      answer += plusland[i].num;
    }
    for (int i = 0; i < siz + 1; i++) {
      answer += minusland[i].num;
    }
  } else {
    for (int i = 0; i < siz; i++) {
      answer += minusland[i].num;
    }
    for (int i = 0; i < siz + 1; i++) {
      answer += plusland[i].num;
    }
  }
  cout << answer;
  return 0;
}
