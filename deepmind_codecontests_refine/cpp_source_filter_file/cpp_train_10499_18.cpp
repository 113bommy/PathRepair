#include<iostream>
using namespace std;
int main(){
	char a,b;
	cin>>a>>b;
  	char hd[2]=['H','D'];
  	cout<<(a=='H'?b:hd[abs((b=='D')-1)] )<<endl;
}