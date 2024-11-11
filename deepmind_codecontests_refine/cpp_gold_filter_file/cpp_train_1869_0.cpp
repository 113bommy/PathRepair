#include <bits/stdc++.h>
#define r(i,n) for(int i=0;i<n;i++)
using namespace std;
int main(){
	int n;
	cin>>n;
	while(n--){
		string s;
		cin>>s;
		int f=0;
		r(i,s.size()-1)if(s[i]==s[i+1])f++;
		cout<<(f?"No":"Yes")<<endl;
	}
}