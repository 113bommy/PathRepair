#include<iostream>
#include<algorithm>
#define F 114514
using namespace std;int s[F],e[F],q;bool c[F];void a(bool t,bool r){if(t){if(c[q-1]!=r){if(q==1)e[0]++,c[0]=r;else{e[q-2]=e[q-1]+1;q--;}}else e[q-1]++;return;}if(c[q-1]!=r)s[q]=e[q-1],e[q]=s[q]+1,c[q]=r,q++;else e[q-1]++;return;}int main(){int n,t;while(true){cin>>n;if(!n)break;cin>>t;s[0]=0,e[0]=1,c[0]=t,q=1;for(int i=1;i<n;i++){cin>>t;a(i%2,t);}int s=0;for(int i=0;i<q;i++)if(!c[i])s+=e[i]-s[i];cout<<s<<endl;}return 0;}