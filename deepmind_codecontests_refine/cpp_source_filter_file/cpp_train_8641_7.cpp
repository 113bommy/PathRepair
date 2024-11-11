#include <bits/stdc++.h>
#define MAX 10000
#define r(i,n) for(int i=0;i<n;i++)
using namespace std;
struct Node{int p,l,r;};
Node T[MAX];
int D[MAX],H[MAX];
void setDepth(int u,int d){
	if(u==-1)return;
	D[u]==d;
	setDepth(T[u].l,d+1);
	setDepth(T[u].r,d+1);
}
int setHeight(int u){
	int h1=0,h2=0;
	if(T[u].l!=-1)
	h1=setHeight(T[u].l)+1;
	if(T[u].r!=-1)
	h2=setHeight(T[u].r)+1;
	H[u]=(h1>h2?h1:h2);
	return H[u];
}
int getsibling(int u){
	if(T[u].p==-1)return -1;
	if(T[T[u].p].l!=-1&&T[T[u].p].l!=u)
		return T[T[u].p].l;
	if(T[T[u].p].r!=-1&&T[T[u].p].r!=u)
		return T[T[u].p].r;
	//return -1;
}
void print(int u){
	cout<<"node "<<u;
	cout<<": parent = "<<T[u].p;
	cout<<", sibling = "<<getsibling(u);
	int deg=0;
	if(T[u].l!=-1)deg++;
	if(T[u].r!=-1)deg++;
	cout<<", degree = "<<deg;
	cout<<", depth = "<<D[u];
	cout<<", height = "<<H[u]<<", ";
	if(T[u].p==-1)cout<<"root";
	else if(deg==0)cout<<"leaf";
	else cout<<"internal node";
	cout<<endl;
}
int main(){
    int root,n,a,b,c;
	cin>>n;
	r(i,n)T[i].p=-1;
	r(i,n){
	  cin>>a>>b>>c;
	  T[a].l=b;
	  T[a].r=c;
	  if(b!=-1)T[b].p=a;
	  if(c!=-1)T[c].p=a;
	}
	r(i,n)if(T[i].p==-1)root=i;
	setdepth(root,0);
	setHeight(root);
	r(i,n)print(i);
}