#include<iostream>
using namespace std;
int n,f,i;
int main(){
	cin>>n;
	for(i=1;i<=2e6;i++){
		f=(f*10+7)%n;
		if(!f){
			cout<<i<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
	return 0;
}
