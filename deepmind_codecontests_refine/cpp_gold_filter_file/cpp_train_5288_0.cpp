#include<iostream>
using namespace std;
int N,K,R,S,P,a,i;
string T;
bool f[1<<17];
int main(){
	cin>>N>>K>>R>>S>>P>>T;
	for(i=0;i<N;i++){
		if(i<K||T[i-K]!=T[i]||!f[i-K]){
			a+=T[i]=='r'?P:T[i]=='s'?R:S;
			f[i]=true;
		}
	}
	cout<<a<<endl;
}
