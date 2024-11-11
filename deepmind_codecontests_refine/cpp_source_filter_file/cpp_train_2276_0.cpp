#include<iostream>

using namespace std;

int main(){
	int n , a , b , x,f;
	cin>>n>>a>>b;
	f = 0;
		for(int i = 0 ; i < n ; i++){
		cin>>x;
		if(x>=b || x < a) f++
		}
	cout<<f<<endl;

return 0;
}