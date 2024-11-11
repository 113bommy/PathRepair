#include <stdio.h>
 
int main(){
  int n, m, tl[10001], tr[10001], i, j, k, befor, maxnum;
 
  while(1){
    scanf_s("%d %d", &n, &m);
    if(n==0 && m==0) break;

    for(i=0;i<n;i++){
      scanf_s("%d", &tl[i]);
    }
    tl[i]=1000001;
 
    for(i=0;i<m;i++){
      scanf_s("%d", &tr[i]);
    }
    tr[i]=1000001;

	j=0;
	k=0;
	maxnum=-1;
	befor=0;
	for(i=0;i<n+m+1;i++){
		if(tl[j]>=tr[k]){
			if(maxnum<tl[j]-befor){
				maxnum = tl[j] - befor;
			}
			befor=tl[j];
			j++;
		}
		else if(tl[j]<tr[k]){
			if(maxnum<tr[k]-befor){
				maxnum = tr[k] - befor;
			}
			befor=tr[k];
			k++;
		}
		if(tl[j]==tr[k]){
			i++;
			k++;
		}
	}
    printf("%d\n", maxnum);
  }
  return 0;
}