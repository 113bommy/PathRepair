#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include<algorithm>
using namespace std;

bool hikaku(const pair<int,string>& A,const pair<int,string>& B){
	return A.first > B.first;
}
int main(){
	int n,k,win,lose,les;
	string s;
	
	while(cin >> n,n){
		vector<pair<int,string> >p; // vector < pair <string, int> >p;
	
		for(int i=0;i<n;i++){
			cin >> s ;// cin >> s;
			les = 0;
			for(int j=0;j<n-1;j++){
				cin >> k;
				if(k==0)
				les+=10;//les++;
				if(k==2)//if(k==1)
				les+=1;
			}
			p.push_back( make_pair(les,s) );
		}
		stable_sort(p.begin(),p.end(),hikaku );
		//stable_sprt(p.begin(),p.end(),greater<pair<string , int> >);
		for(int i=0;i<n;i++)
		cout << p[i].second<<endl;
		
	}
	
	
}