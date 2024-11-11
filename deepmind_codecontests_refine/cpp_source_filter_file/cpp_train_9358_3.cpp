#include<iostream>

using namespace std;

int main(){
	int n;
	while(cin>>n &n){
	for(int i=0;i<9;i++){
		int x;
		cin>>x;
		n-=x;
	}
	
	cout<<n<<endl;
	}
}