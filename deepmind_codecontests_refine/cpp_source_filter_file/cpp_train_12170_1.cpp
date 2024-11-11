#include<iostream>
#include<algorithm>
using namespace std;
int x[100][2],w[100][2],n;
bool cal[110];
int COU(int a,int b){
	while(true){
		if(a<2||b<2)return 1;
		if(a<b){int t=a;a=b,b=t;}
		a%=b;
		if(!a)return b;
	}
}
long long DFS(int q){
	if(!q)return 1;
	q--;
	long long a=DFS(w[q][0]),b=DFS(w[q][1]);
	return (a*b*(x[q][0]+x[q][1]))/COU(a*x[q][0],b*x[q][1]);
}
int main(){
	while(true){
		cin>>n;
		if(!n)break
		for(int i=0;i<n;i++)cal[i]=false;
		for(int i=0;i<n;i++){
			cin>>x[i][0]>>x[i][1]>>w[i][0]>>w[i][1];
			cal[w[i][0]-1]=true,cal[w[i][1]-1]=true;
		}
		for(int i=0;i<n;i++)if(!cal[i])cout<<DFS(i+1)<<endl;
	}
	return 0;
}