#include <bits/stdc++.h>
using namespace std;
int i = 0;
char name[110][30];
char tmp[10];
bool checkT() {
  for (int i = 1; i < 6; i++)
    if (tmp[i] != tmp[i - 1]) return (false);
  return (true);
}
bool checkP() {
  for (int i = 1; i < 6; i++)
    if (tmp[i] >= tmp[i - 1]) return (false);
  return (true);
}
vector<int> VT;
vector<int> VP;
vector<int> VG;
void doMagic(vector<int>& V, int& MAX, const int x) {
  if (MAX < x) {
    MAX = x;
    V.clear();
  }
  if (MAX == x) {
    V.push_back(i);
  }
}
void output(const char mes[], const vector<int>& V) {
  printf("%s: %s", mes, name[V[0]]);
  for (int i = 1; i < V.size(); i++) printf(", %s", name[i]);
  printf(".\n");
}
int main() {
  int n;
  scanf("%d\n", &n);
  int MAXT = 0, MAXP = 0, MAXG = 0;
  for (; i < n; i++) {
    int s;
    scanf("%d %s\n", &s, name[i]);
    int cntT = 0, cntP = 0, cntG = 0;
    for (int j = 0; j < s; j++) {
      scanf("%c%c-%c%c-%c%c\n", &tmp[0], &tmp[1], &tmp[2], &tmp[3], &tmp[4],
            &tmp[5]);
      if (checkT()) {
        cntT++;
        continue;
      }
      if (checkP()) {
        cntP++;
        continue;
      }
      cntG++;
    }
    doMagic(VT, MAXT, cntT);
    doMagic(VP, MAXP, cntP);
    doMagic(VG, MAXG, cntG);
  }
  output("If you want to call a taxi, you should call: ", VT);
  output("If you want to order a pizza, you should call: ", VP);
  output("If you want to go to a cafe with a wonderful girl, you should call: ",
         VG);
  return (0);
}
