#include <iostream>
using namespace std;

int main() {
	string s1,s2;
	cin>>s1>>s2;
	for(int i=0;i<3;i++)
	if(s1[i]!=s2[2-i])
	{
		cout<<"NO";
		return 0;
	}
	cout<<"YES";
	
	return 0;
}