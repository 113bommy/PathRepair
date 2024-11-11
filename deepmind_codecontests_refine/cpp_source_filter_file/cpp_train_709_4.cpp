#include<bits/stdc++>
using namespace std;
int n,x;
int odd,even,fr;
int main(){
	cin>>n;
	while(n--){
		cin>>x;
		if(x%4==0) fr++;
		else if(x%2==0) even++;
		else odd++;
	}
	string ans;
	if(even==0){
		if(odd<=fr+1) ans="Yes";
		else ans="No";
	}else{
		if(odd<=fr)ans="Yes";
		else ans="No";
	}
	cout<<ans;
	return 0;
}