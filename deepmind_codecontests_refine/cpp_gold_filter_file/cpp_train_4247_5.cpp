#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
const int MR=500+1;
typedef unsigned long long UL;
const UL INF=-1;
const UL ONE=1;
UL A[MR][MR]={},U[MR],V[MR];
int s[MR],t[MR];

bool work(int n,int p){
	//printf("p=%d\n",p);
	UL pow2 = ONE<<p;
	UL a[MR][MR],u[MR],v[MR];
	memset(a,-1,sizeof(a));
	for(int i=1;i<=n;i++) u[i]=(U[i]&pow2)/pow2;
	for(int i=1;i<=n;i++) v[i]=(V[i]&pow2)/pow2;
	// for(int i=1;i<=n;i++) cout<<u[i]<<" ";printf("\n");
	// for(int i=1;i<=n;i++) cout<<v[i]<<" ";printf("\n");
	bool oki[MR]={},okj[MR]={};
	//先找理论积是1以及理论和是0的
	//理论积是1必须全是1，理论和是0必须全是0
	for(int i=1;i<=n;i++){
		if(s[i]==0 && u[i]==1){//第i行理论积是1
			for(int j=1;j<=n;j++){
				if(a[i][j]!=0) a[i][j]=1;
				else return false;
			}
			oki[i]=1;
		}
		else if(s[i]==1 && u[i]==0){//第i行理论和是0
			for(int j=1;j<=n;j++){
				if(a[i][j]!=1) a[i][j]=0;
				else return false;
			}
			oki[i]=1;
		}
	}
	for(int j=1;j<=n;j++){
		if(t[j]==0 && v[j]==1){//第j列理论积是1
			for(int i=1;i<=n;i++){
				if(a[i][j]!=0) a[i][j]=1;
				else return false;
			}
			okj[j]=1;
		}
		else if(t[j]==1 && v[j]==0){//第j列理论和是0
			for(int i=1;i<=n;i++){
				if(a[i][j]!=1) a[i][j]=0;
				else return false;
			}
			okj[j]=1;
		}
	}
	int cnti[MR]={},cntj[MR]={};
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(u[i]==v[j]) a[i][j]=u[i];
			if(a[i][j]==INF) a[i][j]=0;
			if(a[i][j]==0){
				cnti[i]++;
				cntj[j]++;
			}
		}
	}
	//在不破坏理论积是0的列的前提下，处理理论和是1的行
	for(int i=1;i<=n;i++){
		if(s[i]==1 && u[i]==1){
			for(int j=1;j<=n;j++){
				if(a[i][j]==1){
					oki[i]=1;
					break;
				}
			}
			if(oki[i]) continue;
			for(int j=1;j<=n;j++){
				if(t[j]==0 && v[j]==0 && cntj[j]>1){
					a[i][j]=1;
					cntj[j]--;
					oki[i]=1;
					break;
				}
			}
			if(!oki[i]) return false;
		}
	}
	//在不破坏理论积是0的行的前提下，处理理论和是1的列
	for(int j=1;j<=n;j++){
		if(t[j]==1 && v[j]==1){
			for(int i=1;i<=n;i++){
				if(a[i][j]==1){
					okj[j]=1;
					break;
				}
			}
			if(okj[j]) continue;
			for(int i=1;i<=n;i++){
				if(s[i]==0 && u[i]==0 && cnti[i]>1){
					a[i][j]=1;
					cnti[i]--;
					okj[j]=1;
					break;
				}
			}
			if(!okj[j]) return false;
		}
	}

	//最后check一下没有考虑到的理论积为0的行列
	for(int i=1;i<=n;i++){
		if(s[i]==0 && u[i]==0){
			for(int j=1;j<=n;j++){
				if(a[i][j]==0){
					oki[i]=1;
					break;
				}
			}
			if(!oki[i]) return false;
		}
	}
	for(int j=1;j<=n;j++){
		if(t[j]==0 && v[j]==0){
			for(int i=1;i<=n;i++){
				if(a[i][j]==0){
					okj[j]=1;
					break;
				}
			}
			if(!okj[j]) return false;
		}
	}
	// for(int i=1;i<=n;i++){
	// 	for(int j=1;j<=n;j++){
	// 		cout<<a[i][j]<<" ";
	// 	}printf("\n");
	// }
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			
			A[i][j]+=a[i][j]<<p;
		}
		
	}


	return true;
}

int main() {
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>s[i];
	for(int i=1;i<=n;i++) cin>>t[i];
	for(int i=1;i<=n;i++) cin>>U[i];
	for(int i=1;i<=n;i++) cin>>V[i];
	// for(int i=1;i<=n;i++) cout<<U[i]<<" ";printf("\n");
	// for(int i=1;i<=n;i++) cout<<V[i]<<" ";printf("\n");
	bool flag;
	for(int p=0;p<64;p++){
		flag=work(n,p);
		if(!flag){
			printf("-1\n");
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<n;j++){
			cout<<A[i][j]<<" ";
		}
		cout<<A[i][n]<<"\n";
	}
    return 0;
}