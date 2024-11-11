#include <iostream>
#include <set>
using namespace std;
string s;
int main()
{
	string s;
	cin>>s;
	int N=s.length();
	if(N<26){
        for(char i='a';i<='z';i++){
            if(s.find(i)==-1){
                cout<<s<<i;
                return 0;
            }
        }
	}
	else{
        set<char>x;
        while(!s.empty()){
            char p=s.back();
            s.pop_back();
            x.insert(p);
            if(*x.rbegin()!=p){
                cout<<s<<*x.upper_bound(p);
                return 0;
            }
        }
	}
	cout<<-1;
}
