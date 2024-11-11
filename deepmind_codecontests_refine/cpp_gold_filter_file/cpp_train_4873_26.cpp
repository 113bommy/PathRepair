#include <bits/stdc++.h>
using namespace std;

int main(){
	int p,q,r;
    cin >> p >> q >> r;
    cout << min(min(p+q,q+r),p+r) << endl;
}
