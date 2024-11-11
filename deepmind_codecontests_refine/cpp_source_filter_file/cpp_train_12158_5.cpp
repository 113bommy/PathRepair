#include <iostream>
#include <set>

using namespace std;

set<string>S;

int main() {
	int n;
	cin>>S;
	for(int i=0;i<n;i++) {
		string s;
		cin>>s;
		S.push(s);
	}
	cout<<S.size();
	return 0;
}