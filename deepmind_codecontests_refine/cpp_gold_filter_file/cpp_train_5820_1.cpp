#include<stdio.h>
int n,m;
int i,j;
int req[100],no[100];
int d;

void sort(int a[], int n,int b[]){
	int x;
	for(i=n-1;i>0;i--){
		for(j=0;j<i;j++){
			if(a[j]>a[j+1]){
				x=a[j];
				a[j]=a[j+1];
				a[j+1]=x;
				x=b[j];
				b[j]=b[j+1];
				b[j+1]=x;
			}
			else if(a[j]==a[j+1])if(b[j]<b[j+1]){
				x=b[j];
				b[j]=b[j+1];
				b[j+1]=x;
			}
		}
	}
}

int main(){
	while(1){
		scanf("%d %d",&n,&m);
		if(n==0&&m==0)return 0;
		for(i=0;i<m;i++)req[i]=0;
		for(i=0;i<m;i++)no[i]=i+1;
		for(i=0;i<n;i++)for(j=0;j<m;j++){
			scanf("%d",&d);
			if(d==1)req[j]++;
		}
		sort(req,m,no);
		for(i=m-1;i>=0;i--){
			printf("%d",no[i]);
			if(i!=0)printf(" ");
		}
		printf("\n");
	}
}