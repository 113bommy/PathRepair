#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <bitset>
using namespace std;
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
typedef long long ll;
#define pii pair<int,int>
map<pii, int> Map;
int n,m,k;
int UF[2][201000];
int Find(int pv, int a) {
  if(UF[pv][a] == a) return a;
  return UF[pv][a] = Find(pv, UF[pv][a]);
}
void Merge(int pv, int a, int b) {
  a = Find(pv, a);
  b = Find(pv, b);
  if(a != b) UF[pv][a] = b;
}
int main(){
  int i, a, b;
  scanf("%d%d%d",&n,&m,&k);
  for(i=1;i<=n;i++)UF[0][i]=UF[1][i]=i;
  for(i=0;i<m;i++){
    cin>>a>>b;
    Merge(0,a,b);
  }
  for(i=0;i<k;i++){
    cin>>a>>b;
    Merge(1,a,b);
  }
  for(i=1;i<=n;i++){
    Map[pii(Find(0,i),Find(1,i))]++;
  }
  for(i=1;i<=n;i++){
    printf("%d%c",Map[pii(Find(0,i),Find(1,i))],i==n-1?'\n':' ');
  }
  return 0;
}
