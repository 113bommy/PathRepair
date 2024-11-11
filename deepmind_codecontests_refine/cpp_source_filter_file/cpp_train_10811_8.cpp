#include<stdio.h>
using namespace std;
 
int main(){
	int x,Max;x=Max=0;
	int n;string s;cin>>n>>s;
	for(char c:s){
		if(c=='I')x++;
		else x--;
		Max=max(Max,x);
	}
	cout<<Max<<endl;
}