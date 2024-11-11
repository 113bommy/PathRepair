#include<iostream>
using namespace std;
int main(){
	int X,Y;
	cin>>X>>Y;
	if(2*X<=Y&&4*X>=Y&&Y%2==0)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}