#include <bits/stdc++.h>
using namespace std;

int main(){
    int x, y, a, b, c, t;
    cin >> a >> b >> c >> x >> y;
    t = min(min(2*c*x+b*y*max(0,y-x), a*b*max(x-y)+2*c*x), a*x+b*y);
    cout << t;
    return 0;
}