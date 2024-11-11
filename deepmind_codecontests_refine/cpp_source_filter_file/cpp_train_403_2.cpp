#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	while(1){
		int n;
		cin>>n;
		if(n==0)return;
		vector<pair <int,int>>v;
		for(int i=0;i<n;i++){
			int a,b;
			cin>>a>>b;
			v.push_back(make_pair(b,a));
		}
		sort(begin(v),end(v));
		int w=0;
		for(int i=0;i<n;i++){
			w+=v[i].second;
			if(w>v[i].first){
				cout<<"No"<<endl;
				goto next;
			}
		}
		cout<<"Yes"<<endl;
		next:;
	}
	return 0;
} 