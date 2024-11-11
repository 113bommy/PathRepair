#include <bits/stdc++.h>
using namespace std;
int main() {
  int crew_num;
  cin >> crew_num;
  cin.ignore();
  vector<string> crew(crew_num);
  for (int count = 0; count < crew_num; count++) {
    getline(cin, crew[count]);
  }
  int range = 7;
  char p[100][8];
  char name[100][12];
  char priorty[5][8];
  strcpy(priorty[0], "rat");
  strcpy(priorty[1], "woman");
  strcpy(priorty[2], "child");
  strcpy(priorty[3], "man");
  strcpy(priorty[4], "captian");
  int num = 0;
  int n;
  int k;
  for (int i = 0; i < crew_num; i++) {
    num = 0;
    k = 0;
    while (crew[i][k] != ' ') {
      name[i][num] = crew[i][k];
      k++;
      num++;
    }
    name[i][num] = '\0';
    n = k + 1;
    num = 0;
    while (crew[i][n] != '\0') {
      p[i][num] = crew[i][n];
      n++;
      num++;
    }
    p[i][num] = '\0';
  }
  for (int m = 0; m < 5; m++) {
    if (m == 2) {
      continue;
    } else if (m == 1) {
      for (int i = 0; i < crew_num; i++) {
        if (strcmp(p[i], priorty[m]) == 0 ||
            strcmp(p[i], priorty[m + 1]) == 0) {
          cout << name[i] << "\n";
        }
      }
    } else {
      for (int i = 0; i < crew_num; i++) {
        if (strcmp(p[i], priorty[m]) == 0) {
          cout << name[i] << "\n";
        }
      }
    }
  }
  cout << "\n";
  return 0;
}
