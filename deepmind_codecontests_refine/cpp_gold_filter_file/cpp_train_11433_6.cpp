#include <iostream>
#include <string>
using namespace std;
int main(){
	string str;
	cin>>str;
	if (str.size()==3) cout<<str[2]<<str[1]<<str[0]<<endl;
	else cout<<str<<endl;
	return 0;
}