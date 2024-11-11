#include "bits/stdc++.h"
using namespace std;
int a,b,c;
int n;
int main(){
cin>>n;
pair<int,int> p[n];
for (int i = 0; i < n; ++i) {
	cin>>a>>b;
	p[i].second=a;p[i].first=-b;
}
sort(p,p+n);
cout<<p[0].second<<" "<<-p[0].first<<endl;
//cout<<p[n-1].second<<" "<<-p[n-1].first<<endl;
}