#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    string s;cin>>s;
    int n=s.size();
    int c=0;
    for (int i=0;i<n;i++) {
        if (i%2==0&&s[i]=='1'||i%2==1&&s[i]=='0')
            c++;
    cout<<min(c,n-c)<<endl;
    return 0;
}