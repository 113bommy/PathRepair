#include<cstdio>
#include<iostream>

#define REP(i,s,n) for(register int i=s;i<n;i++)
#define rep(i,n) REP(i,0,n)
#define MAX 500010

using namespace std;

long long depth[MAX],L[MAX],R[MAX],N,noSaveDp[MAX],saveDp[MAX],leaf[MAX];

int main(){
  scanf("%d",&N);
  depth[0] = leaf[N-1] = 1;
  rep(i,N-1){
    scanf("%d %d",&L[i],&R[i]);
    depth[--L[i]] = depth[--R[i]] = depth[i] + 1;
  }

  for(i = N-2;i>=0;i--){
    leaf[i] = leaf[L[i]] + leaf[R[i]];
    saveDp[i] = noSaveDp[i] = noSaveDp[L[i]] + noSaveDp[R[i]] + leaf[L[i]] + leaf[R[i]];
    saveDp[i] = min(saveDp[i],
		    min(noSaveDp[L[i]]+leaf[L[i]]+1+saveDp[R[i]],
			noSaveDp[R[i]]+leaf[R[i]]+1+saveDp[L[i]]));
    saveDp[i] = min(saveDp[i],
		    saveDp[L[i]]+1+depth[i]-1+1+saveDp[R[i]]);
  }
  printf("%d\n",saveDp[0]);
  return 0;
}