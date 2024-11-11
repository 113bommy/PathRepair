#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	string inStr, buf;
	int cnt =0;
	while(cin>>inStr, !cin.eof()) {
		buf = inStr;
		sort(inStr.rbegin(), inStr.rend());
		if(buf == inStr) cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}