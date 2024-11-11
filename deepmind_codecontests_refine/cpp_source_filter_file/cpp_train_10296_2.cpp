#include <iostream>
#include <string>
using namespace std;

// sツづ個静ヲツ督ェツつゥツづァツづ個連ツ堕アツ青板づーツ陛板つキ
// sst ツづ按づァツ　return 2
int f(string s)
{
	unsigned int count;
	for(count = 1; count < s.size(); count++){
		if(s.at(count-1) != s.at(count)) break;
	}
	return count;
}

int main()
{
	int n;
	string str;
	while(1){
		cin>>n; if(n == 0) break;
		cin>>str;
		for(int i = 0; i < n; i++){
			string ans;
			for(unsigned int j = 0; j < str.size();){
				char buf[1024];
				int len = f(str.substr(j));
				sprintf_s(buf, 1024, "%d%c", len, str.at(j));
				ans += buf;
				j += len;
			}
			str = ans;
		}
		cout<<str<<endl;
	}
}