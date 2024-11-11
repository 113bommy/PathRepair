#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int main(){
    int n;
    cin >> n;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>b[i];
    vector<int> s(n+1),t(n+1);
    for(int i=0;i<n;i++){
    	s[a[i]]++;
		t[b[i]]++;
	}
    for(int i=0;i<=n;i++)
    if(s[i]+t[i]>n){
        cout<<"No"<<endl;
        return 0;
    }
    for(int i=0;i<n;i++){
    	s[i+1]+=s[i];
		t[i+1]+=t[i];
	}
    int x=-2e5-10;
    for(int i=0;i<n;i++)x=max(x,s[i+1]-t[i]);
    cout<<"Yes"<<endl;
    for(int i=0;i<n;i++){
    	cout<<b[(i+n-x)%n];
		if(i==n-1)cout<<endl;
		else cout<<' ';
	}
    return 0;
}