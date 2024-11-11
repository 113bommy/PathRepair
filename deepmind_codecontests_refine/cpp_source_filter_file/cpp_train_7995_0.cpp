include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
int main(void){
	int n,m,i,ans=0;
	cin>>n>>m;
	int x[m],sa[m-1];
	for(i=0;i<m;i++)cin>>x[i];
	sort(x,x+m);
	for(i=1;i<m;i++)sa[i-1]=x[i]-x[i-1];
	sort(sa,sa+m-1);
	for(i=0;i<m-n;i++)ans+=sa[i];
	cout<<ans<<endl;
}