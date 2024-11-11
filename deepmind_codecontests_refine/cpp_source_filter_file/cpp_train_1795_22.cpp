#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> seqis;
  for (int next = 1; next <= 11; next++) {
    int var;
    scanf("%d", &var);
    seqis.push_back(var);
  }
  for (int next = 1; next <= 11; next++) {
    int var = seqis.back();
    seqis.pop_back();
    double aresult = sqrt(abs(var));
    double bresult = pow(var, 3) * 5;
    double result = aresult + bresult;
    if (4000 >= result) {
      printf("f(%d) = %.2f\n", var, result);
    }
    if (4000 < result) {
      printf("f(%d) = MAGNA NIMIS!\n", var);
    }
  }
}
