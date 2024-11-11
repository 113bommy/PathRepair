#include<bits/stdc++.h>
using namespace std;

int main()
{
  	string s;
  	cin>>s;
  	int n = s.length();
  	if(((s[0] == s[n-1]) && (n % 2 == 1)) || ((s[0] != s[n-1]) && (n % 2 == 0)))
      	cout<<"Second\n";
  	else
      	cout<<"First\n";
	return 0;
}
