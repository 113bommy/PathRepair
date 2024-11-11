#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;
#define N 500050
char w[N];
int nxt[N],n,txn[N];
bool check1(int x) {
	if(x<2) return 1;
	int t=x-nxt[x];
	return t==x||x%t>0;
}
bool check2(int x) {
	if(x>n-1) return 1;
	int t=(n-x+1)-(n-txn[x]+1);
	return t==(n-x+1)||(n-x+1)%t>0;
}
int main() {
	fread(w+1,500005,stdin);
	n=strlen(w+1)-1;
	if(n==1) {puts("1\n1\n"); return 0;}
	if(n==2) {
		if(w[1]==w[2]) puts("2\n1\n");
		else puts("1\n1\n");
		return 0;
	}
	int i;
	int flg=0;
	for(i=2;i<=n;i++) if(w[i]!=w[i-1]) {flg=1;break;}
	if(!flg) {printf("%d\n1\n",n); return 0;}
	nxt[1]=0;
	int j=0;
	for(i=2;i<=n;i++) {
		for(;j&&w[i]!=w[j+1];j=nxt[j]) ;
		if(w[i]==w[j+1]) j++;
		nxt[i]=j;
	}
	int t=n-nxt[n];
	if(t==n||n%t) {
		printf("1\n1\n"); return 0;
	}
	printf("%d\n",2);
	txn[n]=n+1;
	j=n+1;
	for(i=n-1;i;i--) {
		for(;j<=n&&w[i]!=w[j-1];j=txn[j]) ;
		if(w[i]==w[j-1]) j--;
		txn[i]=j;
	}
	int ans=0;
	for(i=1;i<n;i++) {
		if(check1(i)&&check2(i+1)) ans++;
	}
	printf("%d\n",ans);
}
