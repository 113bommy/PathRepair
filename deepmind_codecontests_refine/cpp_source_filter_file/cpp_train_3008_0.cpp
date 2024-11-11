#include<iostream>
#include<algorithm>
using namespace std;

int main(){
 while(true){
	int N;
	cin>>N;

	if(N==0)break;

	int n[10]=[0];
	int m=0;

	for(int i=0;i<100;i++){
		char c;
		cin>>c;

		n[i%N]++;

		if(c=='S'){
			m+=n[i%N];
			n[i%N]=0;
		}else if(c=='L'){
			n[i%N]+=m;
			m=0;
		}

	}
	sort(n,n+N);

	for(int i=0;i<N;i++){
		cout<<n[i]<<' ';
 	}
 	cout<<m<<endl;
 }
 return 0;
}