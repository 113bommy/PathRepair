#include<bit/stdc++.h>

int main(){
	int n,k,x,ct=0;
  	scanf("%d%d",&n,&k);
  	while(n--){
    	scanf("%d",&x);
      	if(x>=k) ct++;
    }
  printf("%d",ct);
  
}
