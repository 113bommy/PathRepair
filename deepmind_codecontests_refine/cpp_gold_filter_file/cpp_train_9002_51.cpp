#include <bits/stdc++.h>
using namespace std;
long long t, fldgjdflgjhrthrl, fldggfhfghjdflgjl, fldgjdflgrtyrtyjl,
    ffgfldgjdflgjl;
int main() {
  long long sum = 0;
  scanf("%I64d", &t);
  while (t--) {
    cin >> fldgjdflgjhrthrl >> fldggfhfghjdflgjl >> fldgjdflgrtyrtyjl >>
        ffgfldgjdflgjl;
    sum += (fldgjdflgrtyrtyjl - fldgjdflgjhrthrl + 1) *
           (ffgfldgjdflgjl - fldggfhfghjdflgjl + 1);
  }
  printf("%I64d\n", sum);
  return 0;
}
