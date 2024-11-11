#include <bits/stdc++.h>
using namespace std;

int main(){
    int x, y, a, b, c, t;
    cin >> a >> b >> c >> x >> y;
    t = min(min(2*c*x+b*max(0,y-x), a*max(0,x-y)+2*c*y), a*x+b*y);
    cout << t;
    return 0;
}