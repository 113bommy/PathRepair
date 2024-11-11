#include<cstdio>
#include<algorithm>
using namespace std;
int n,tot,now,x[510],b[510],a[250010];
bool cmp(int a,int b){
	return x[a]<x[b];
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",x+i);
		if(a[x[i]]){
			puts("No");
			return 0;
		}
		a[x[i]]=i;
		b[++tot]=i;
	}
	sort(b+1,b+n+1,cmp);
	now=1;
	for(int k=1;k<=n;k++){
		int i=b[k],cnt=i-1;
		while(cnt&&now<x[i]){
			if(!a[now]){
				cnt--;
				a[now]=i;
			}
			now++;
		}
		if(cnt){
			puts("No");
			return 0;
		}
	}
	int now=n*n;
	for(int k=n;k;k--){
		int i=b[k],cnt=n-i;
		while(cnt&&now>x[i]){
			if(!a[now]){
				cnt--;
				a[now]=i;
			}
			now--;
		}
		if(cnt){
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	for(int i=1;i<=n*n;i++)
		printf("%d ",a[i]);
	return 0;
}