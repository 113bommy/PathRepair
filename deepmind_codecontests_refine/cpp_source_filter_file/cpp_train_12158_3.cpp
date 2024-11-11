#include <bists/stdc++.h>
using namespace std;

int main(){
	int n;
  	cin>>n;
  	string s;
  	map<string,int> history;
  	while(cin>>s){
      history[s]++;
    }
  	cout<<history.size()<<endl;
}