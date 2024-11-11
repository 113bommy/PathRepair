#include<cstdio>

int main(){
	int i,j;
	for(int n;scanf("%d",&n),n;){
		int p[10]={};
		for(i=n;i;--i)
			scanf("%d",&j),++p[j];
		for(i=0;i<10;++i,puts("")){
			for(j=0;j<p[i];++j)
				printf("*");
			if(!p[i])printf("-");
		}
	}
}