#include <bits/stdc++.h>
std::map <std::string,int> mp;
std::string s;
long long ans=0;
int main(){
	int n; std::cin>>n;
	while (std::cin >> s, std::sort (s.begin(),s.end()), n--){ ans+=mp[s]++; }
	std::cout<<ans;
}
