#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
  	int b=0;
  	for(int i=0;i<s.size()/2;i++)
    	if(s[i]!=s[s.size()-1-i])
        	b++;
    cout<<b;
}
