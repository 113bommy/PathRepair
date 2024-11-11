#include<bits/stdc++.h>
using namespace std;
int S(long long x) {
if(x < 10) return x;
return (x%10) + S(x/10);
}
int main() {
long long s;
cin >> s;
int ans = S(x);
int cur = 0;
while(x) {
x/=10;
cur += 9;
ans = max(ans, cur + S(x-1));
}
cout << ans;

}