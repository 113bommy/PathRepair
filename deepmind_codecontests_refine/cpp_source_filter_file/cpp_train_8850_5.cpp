#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
	string w,t;
	int ans=0;
	cin >> w;
	while(cin >>t){
		if(t=="END_OF_TEXT") break;
		transform(t.begin(),t.end(),t.begin(),tolower);

		if(t==w) ans++;
	}
	cout << ans << endl;
	return 0;
}