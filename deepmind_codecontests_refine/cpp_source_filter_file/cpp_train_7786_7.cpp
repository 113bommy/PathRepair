include <iostream>
using namespace std;
 
int main(){
	long long s;
	cin>>s;
	
	const int v=1000000000;
	
	int x=(v-s%v)%v;
	int y=(s+x)/v;
	
	cout<<"0 0 1000000000 1 "<<x<<" "<<y<<endl;
}