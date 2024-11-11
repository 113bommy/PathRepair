#include <bits/stdc++.h>
using namespace std;
int hashh[200005],ans[200005],memo[1<<26],arr[26];

int main(){
	for(int i=0;i<(1<<26);i++) memo[i]=INT_MAX;
	string s;
	cin >> s;
	int len=s.length();
	s="*"+s;
	hashh[0]=0;
	for(int i=1;i<=len;i++){
		arr[s[i]-'a']++;
		int hv=0;
		for(int j=0;j<26;j++){
			if(arr[j]%2) hv=(hv|(1<<j));
		}
		hashh[i]=hv;
	}
	memo[0]=0;
	for(int i=1;i<=len;i++){
		ans[i]=i;
		if(memo[hashh[i]]!=INT_MAX) ans[i]=min(ans[i],memo[hashh[i]]+1);
		for(int j=0;j<26;j++){
			if(memo[hashh[i]^(1<<j)]!=INT_MAX) ans[i]=min(ans[i],memo[hashh[i]^(1<<j)]+1);
		}
		memo[hashh[i]]=min(memo[hashh[i]],ans[i]);
	}

	cout << ans[len] << endl;

	return 0;
}