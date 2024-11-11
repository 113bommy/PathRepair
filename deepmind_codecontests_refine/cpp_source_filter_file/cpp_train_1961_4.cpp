#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
  	cin>>s;
  	int cur=0;
  	for (char c:s){
    	cur+=c-'0';
    }
  	cout<<max(cur,(int)s[0]-'0'+9*(s.size()-1))<<endl;
  	return 0;
}
