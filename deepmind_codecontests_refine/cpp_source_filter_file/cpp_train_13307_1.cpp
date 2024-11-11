#include <iostream>
#include <string>

using namespace std;

int main(){
	int n;
	long long march[5] = {0};
	const char pat = "MARCH";

	cin >> n;
	for(int i=0; i<n ;i++){
		string s;
		cin >> s;
		for(int t=0; t<5; t++){
			if(pat[t] == s[0])
				march[t] += 1;
		}
	}

	long long ans = 0;

	for(int a=0; a<5; a++)
		for(int b=a+1; b<5; b++)
			for(int c=b+1; c<5; c++){
				ans += march[a] * march[b] * march[c];
			}

	cout << ans << endl;

	return 0;
}
