#include <iostream>
#include <string>
using namespace std;
int main(){
	string s;
	cin>>s;
	for(int i=0;i<20;i++){
		cout<<s[20-1-i];
	}
	cout<<endl;
    return 0;
}