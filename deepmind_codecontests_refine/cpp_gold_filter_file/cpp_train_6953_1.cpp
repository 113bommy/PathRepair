#include <bits/stdc++.h>
using namespace std;
int main(){
int N; cin >> N; string ans="No\n";
for(int i=1; i<10; i++){ if(N%i==0&&N/i<10){ ans="Yes\n"; break; } }
cout << ans;
}