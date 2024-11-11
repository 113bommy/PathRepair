#include <iostream>
#include <algorithm>
#include <cassert>
#include <cctype>
#include <complex>
#include <cstdio>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;

typedef __int64 ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
struct edge{int a,b;};
edge e[50];

mat mul(mat&A,mat&B){
	mat C(A.size(),vec(B[0].size()));
	for(int i=0;i<A.size();i++){
		for(int k=0;k<B.size();k++){
			for(int j=0;j<B[0].size();j++){
				C[i][j]=(C[i][j]+A[i][k]*B[k][j]);
				if(C[i][j]>1)C[i][j]=1;
			}
		}
	}
	return C;
}

mat pow(mat A,ll n){
	mat B(A.size(),vec(A.size()));
	for(int i=0;i<A.size();i++)B[i][i]=1;
	int f=1;
	while(n){
		if(n&1)B=mul(B,A);
		A=mul(A,A);
		if(f)for(int i=0;i<A.size();i++)A[i][i]=0;
		f=0;
		n>>=1;
	}
	return B;
}

int N,M,Z;

int main(){
	while(cin>>N>>M>>Z){
		if(!N)return 0;
		mat A(M*2+1,vec(M*2+1));
		int s,d;
		for(int i=0;i<M;i++)cin>>e[i].a>>e[i].b;
		for(int i=0;i<M;i++){
			if(e[i].a==1)A[0][2*i+1]=1;
			if(e[i].b==1)A[0][2*i+2]=1;
		}
		for(int i=0;i<M;i++)for(int j=0;j<M;j++){
			if(e[i].b==e[j].a&&e[i].a!=e[j].b)A[2*i+1][2*j+1]=1;
			if(e[i].b==e[j].b&&e[i].a!=e[j].a)A[2*i+1][2*j+2]=1;
			if(e[i].a==e[j].a&&e[i].b!=e[j].b)A[2*i+2][2*j+1]=1;
			if(e[i].a==e[j].b&&e[i].b!=e[j].a)A[2*i+2][2*j+2]=1;
		}
		//for(int i=0;i<=M*2;i++){for(int j=0;j<=M*2;j++)cout<<A[i][j]<<" ";cout<<endl;}
		A=pow(A,Z);
		//for(int i=0;i<=M*2;i++){for(int j=0;j<=M*2;j++)cout<<A[i][j]<<" ";cout<<endl;}
		int f=0;
		for(int i=1;i<=M*2;i++)if(A[0][i]&&(i%2&&e[i/2].b==N||i%2==0&&e[i/2-1].a==N))f=1;
		if(f)cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}
}