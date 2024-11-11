#include <bits/stdc++.h>
using namespace std;
int main(){
    int64_t n,a,b;
    cin >> n >> a >> b;
    
    cout << n/(a+b)*a + min(n%(a+b),a) << endl;
}