#include<iostream>
#include<vector>
#include<set>
using namespace std;
typedef vector<int> vec;
int main(){
	int n,x,s;
	while(cin>>n,n){
		vec tab[31];
		set<int> have[60];
		set<int>::iterator ite;
		int now=0;
		while(n!=now++){
			cin>>x;
			for(int i=0;i<x;i++){
				cin>>s;
				tab[s].push_back(now);
			}
		}
		for(int i=1;i<=n;i++)
		have[i].insert(i);
		for(int i=1;i<=30;i++){
			vec box;
			for(int j=0;j<(int)tab[i].size();j++){
				box.push_back(tab[i][j]);
				ite=have[tab[i][j]].begin();
				while(ite!=have[tab[i][j]].end()){
					box.push_back(*ite);
					ite++;
				}
			}
			for(int j=0;j<(int)tab[i].size();j++){
				for(int k=0;k<box.size();k++)
					have[tab[i][j]].insert(box[k]);
				if((int)have[tab[i][j]].size()==n){
					cout<<i<<endl;
					goto end;
				}
			}
		}
			cout<<"NO"<<endl;
		end:
	}
	return 0;
}