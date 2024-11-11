#include <iostream>
#include <vector>
#include <list>
using namespace std;

int n,m,a;
int gi;

int main(void){
	while(cin>>n,n){
		std::vector<int> day[31];
		std::list<int> member[51];
		for(int i=0;i<n;i++)member[i].push_front(i);
		for(int i=0;i<n;i++){
			cin>>m;
			for(int j=0;j<m;j++){
				cin>>a;
				day[a].push_back(i);
			}
		}

		for(int gi=0;gi<31;gi++){
			if(day[gi].size()<=1)continue;
			for(int i=1;i<day[gi].size();i++) member[day[gi][0]].merge(member[day[gi][i]]);
			member[day[gi][0]].unique();
			if(member[day[gi][0]].size()==n){
				cout<<gi<<endl;
				goto LAB;
			}
			for(int i=1;i<day[gi].size();i++) member[day[gi][i]]=member[day[gi][0]];
		}
		cout<<"-1"<<endl;
LAB:;
	}
	return 0;
}