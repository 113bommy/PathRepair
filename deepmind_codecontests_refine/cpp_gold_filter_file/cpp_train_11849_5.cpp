#include <bits/stdc++.h>
using namespace std;
int main(){long n,m=1e9+7,i=26;vector<int>a(26,0);cin>>n;string s;cin>>s;while(n--)a[s[n]-'a']++;n=1;while(i--)n=n*(a[i]+1)%m;cout<<n-1;}