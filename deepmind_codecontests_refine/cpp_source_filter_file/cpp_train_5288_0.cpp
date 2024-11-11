#include<iostream>
using namespace std;
int N,K,R,S,P,a,i;
string S;
bool f[1<<17];
int main(){
	cin>>N>>K>>R>>S>>P>>S;
	for(i=0;i<N;i++){
		if(i<K||S[i-K]!=S[i]||!f[i-K]){
			a+=S[i]=='r'?P:S[i]=='s'?R:S;
			f[i]=true;
		}
	}
	cout<<a<<endl;
}
