#include <stdio.h>
int main (){
	int N, A,B;
	scanf("%d %d %d",&N,&A,&B);
	int sum=0;
	for (int i=0 ; i<=N ;i++){
		int digit=0;
		int temp=i;
		while (temp!=0){
			digit+=temp%10;
			temp/=10;
		}
		if (digit>=A&&digit<==B){
			sum+=i;
		}
	}
	printf("%d\n",sum);
}