#include <stdio.h>
int max(int a, int b){
    if(a > b)
    return a;
    else
    return b;
}

int main(){
    while(1 == 1){
	int n, m, i, j, k, tmp;
	int result = 0;
	scanf("%d%d", &n, &m);
	if(n == 0 && m ==0)
	    break;
	int a[n];
	for (i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	for(int i = 0; i < n; i++){
	    for (j = i + 1; j < n; j++){
	        tmp = a[i] + a[j];
	        if(tmp <= m){
	            result = max(result, tmp);
	        }
	    }
	}
	if(result != 0){
	    printf("%d\n", result);
	}else{
	printf("NONE\n");
    }
    }
	return 0;	
}