#include<bits/stdc++.h>
#define rep(i,n)for(ll i=0;i<n;i++)
using namespace std;
typedef long long ll;

char s[2000];
vector<string>ans;

int main() {
	gets(s);
	char*split;
	split = strtok(s, " ,.");
	do {
		if (3 <= strlen(split) && strlen(split) <= 6)
			ans.push_back(string(split));
	} while (split = strtok(NULL, " ,."), split);
	rep(i, ans.size()) {
		cout << ans[i] << (i == ans.size() - 1 ? '\n' : ' ');
	}
	return 0;
}