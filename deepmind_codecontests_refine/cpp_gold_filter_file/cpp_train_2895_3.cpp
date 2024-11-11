#include<iostream>
#include<string>
using namespace std;
int main(){
	string s;
	cin >> s;
	int i;
	int n = s.length();
	int cnt[2] = {0,0};
	for(i=0;i<n;i++){
		if(s[i] == '0') cnt[i%2]++;
		else cnt[(i+1)%2]++;
	}
	if(cnt[0]>cnt[1]) cout << cnt[1];
	else cout << cnt[0];
} 