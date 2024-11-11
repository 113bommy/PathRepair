#include <bits/stdc++.h>
using namespace std;
int main()
{
    cin.tie(0);
	ios::sync_with_stdio(false);
    int n,x,i;cin>>n;
    vector<int>v;
  	for(i=1;i<=n;i++){
    	cin>>x;
    	if(x>i) {cout<<-1<<endl;return;}
    	v.insert(v.begin()+x-1,x);
  	}
  	for(auto it:v)cout<<it<<endl;
    return 0;
}
