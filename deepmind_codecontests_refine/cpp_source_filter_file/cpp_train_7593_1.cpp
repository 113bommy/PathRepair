#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
	int n,m,d,h,i,j,r,s;
	string str;
	for(;cin>>n,n;cout<<r<<endl){
		vector<int>monster(n);
		for(h=i=0;i<n;i++){
			cin>>monster[i];
			if(h<monster[i])h=monster[i];
		}
		vector<pair<int,int> >_all,_single;
		vector<int>all(h+1),single(h+1);
		for(cin>>i;i--;){
			cin>>str>>m>>str>>d;
			if(d){
				if(s[0]=='A')_all.push_back(make_pair(m,d));
				else _single.push_back(make_pair(m,d));
			}
		}
		for(i=1;i<=h;i++){
			all[i]=9999999;
			single[i]=9999999;
			for(j=0;j<_all.size();j++){
				all[i]=min(all[i],all[max(0,i-_all[j].second)]+_all[j].first);
			}
			for(j=0;j<_single.size();j++){
				single[i]=min(single[i],single[max(0,i-_single[j].second)]+_single[j].first);
			}
		}

		r=9999999;
		for(i=0;i<=h;i++){
			s=all[i];
			for(j=0;j<monster.size();j++)s+=single[max(0,monster[j]-i)];
			if(r>s)r=s;
		}
	}
}