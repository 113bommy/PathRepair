#include<iostream>
using namespace std;

int main(){
	int sum;
	int a,b;
	int m,n;
	while(cin>>m,m!=0){
		cin>>n;
		sum=0;
		for(int i=0;i<n;i++){
			cin>>a>>b;
			sum+=b-a;
		}
		if(m<sum)cout<<"OK"<<endl;A
		else cout<<m-sum<<endl;
	}
}