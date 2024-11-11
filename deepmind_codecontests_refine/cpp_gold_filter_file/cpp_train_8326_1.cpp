#include <bits/stdc++.h>
using namespace std;

int main(){
	int a;
	cin>>a;
	int c=0;
	for(int i=0;i<a;i++){
		int b[100];
		cin>>b[i];
		if(b[i]%2==0){
			c++;
		}
		
	}
	cout<<c<<endl;
}
