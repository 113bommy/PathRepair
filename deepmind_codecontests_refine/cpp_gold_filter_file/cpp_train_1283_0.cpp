#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC optimize("s")
#pragma GCC optimize("expensive-optimizations")
#pragma GCC optimize("inline-functions")
template <class A, class B>
ostream& operator<<(ostream& o, pair<A, B>& p) {
  return o << "(" << p.first << ", " << p.second << ")";
}
template <class A, class B>
istream& operator>>(istream& i, pair<A, B>& p) {
  return i >> p.first >> p.second;
}
enum { POS = 0, NEG };
int pos[100010];
int neg[100010];
int said[100010];
bool canCrime[2][100010];
int main() {
  ;
  int numPeople, numTruth;
  while (scanf("%d %d", &numPeople, &numTruth) == 2) {
    int totPos = 0, totNeg = 0;
    for (typeof(numPeople) i = (1); i <= (numPeople); i++) {
      pos[i] = neg[i] = 0;
      canCrime[0][i] = canCrime[1][i] = 0;
    }
    for (typeof(numPeople) i = (1); i <= (numPeople); i++) {
      int x = said[i] = ({
        int a;
        scanf(" %d", &a);
        a;
      });
      if (x > 0) {
        pos[x]++;
        totPos++;
      } else {
        neg[-x]++;
        totNeg++;
      }
    }
    int possibleTruthCount = 0;
    for (typeof(numPeople) i = (1); i <= (numPeople); i++) {
      if (totNeg - neg[i] + pos[i] == numTruth) {
        canCrime[POS][i] = true;
        possibleTruthCount++;
      }
    }
    for (typeof(numPeople) i = (1); i <= (numPeople); i++) {
      int ct = (((said[i]) > 0) ? (said[i]) : -(said[i]));
      if (said[i] > 0) {
        if (canCrime[POS][ct]) {
          if (possibleTruthCount == 1)
            printf("Truth\n");
          else
            printf("Not defined\n");
        } else {
          printf("Lie\n");
        }
      } else {
        if (canCrime[POS][ct]) {
          if (possibleTruthCount == 1)
            printf("Lie\n");
          else
            printf("Not defined\n");
        } else {
          printf("Truth\n");
        }
      }
    }
  }
  return 0;
}
