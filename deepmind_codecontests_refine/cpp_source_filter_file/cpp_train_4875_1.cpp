#include<iostream>
#include<algorithm>
using namespace std;
int a,m,l;
typedef pair<int,int> pa;
int main() {
	cin>>m>>m;
	pa v[m];
	for(pa &x:v)cin>>x.second>>x.first;
	sort(v,v+m);
	for(pa x:v)
		if(x.second>=l){
			l=x.first;
			s++;
		}
	cout<<s;
	return 0;
}