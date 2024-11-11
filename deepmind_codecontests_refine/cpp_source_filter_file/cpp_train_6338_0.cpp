#inclue<stdio.h>
int main(void)
{
	int n,max,i,p[10000],d1,d2,d[10000],x;
	while(1){
		max=0;
		scanf("%d",&n);
		if(n==0)break;
		for(i=0;i<n;i++){
			scanf("%d %d %d",&p[i],&d1,&d2);
			d[i]=d1+d2;
		}
		for(i=0;i<n;i++){
			if(max<d[i]){
				max=d[i];
				x=p[i];
			}
		}
		printf("%d %d\n",x,max);
	}
	return 0;
}