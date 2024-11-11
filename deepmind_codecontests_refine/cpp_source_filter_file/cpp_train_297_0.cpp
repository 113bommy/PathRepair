#include <bits/stdc++.h>
using namespace std;
int main() {
	pair<int,int> a[6];for(int i=0;i<6;i++){
		cin>>a[i].first>>a[i].second;
		if(a[i].first>a[i].second){
			int tmp=a[i].first;
			a[i].first=a[i].second;
			a[i].second=tmp;
		}
	}
	sort(a,a+6);
	set<int>s;
	if(a[0]==a[1]){
		s.insert(a[0].first);
		s.insert(a[1].second);
		if(a[2]==a[3]){
			s.insert(a[2].first);
			s.insert(a[3].second);
			if(a[4]==a[5]){
				s.insert(a[4].first);
				s.insert(a[5].second);
				if(s.size()==1)cout<<"yes\n";
				else if(s.size()==2){
					if(s[0]==s[2]&&s[2]==s[4])cout<<"no\n";
					else cout<<"yes\n";
				}
				else if(s.size()==3){
					for(int i=0;i<6;i++){
						if(s[i].first==s[i].second){
							cout<<"no\n";
							return 0;
						}
					}
					cout<<"yes\n";
				}
				else cout<<"no\n";
			}else cout<<"no\n";
		}else cout<<"no\n";
	}else cout<<"no\n";
	return 0;
}