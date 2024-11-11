#include <bits/stdc++.h>
using namespace std;

int main() {
string correct="CODEFESTIVAL2016";
string s;
cin >> s;
int ans=0;
for(int i=0;i<16;i++){
    if(correct[i] != s[i])ans++;
}
cout << ans << endl;
}
