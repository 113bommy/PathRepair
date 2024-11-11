#include<iostream>
using namespace std;
int main(){
	
	int n, m, x, y, a, b;
	cin >>n >>m >>x >>y;
	
	for(int i=0; i<n; i++){
		
		cin >>a;
		if(a>x) x=a;
		
	}
	for(int i=0; i<m; i++){
		
		cin >>b;
		if(b<y) y=b;
		
	}
	
	cout <<(x<y?"No ":"") <<"War" <<endl;
	
}