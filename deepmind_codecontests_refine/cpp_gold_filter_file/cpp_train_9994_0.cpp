#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
typedef long long ll;
const int mod=1e9+7;
#define lol(i,n) for(int i=0;i<n;i++)

using namespace std;
int a,b,c,d;
int main() {
    cin >> a>>b >> c>>d;
    if(a%2==1&&b%2==1&&(c+d)%2==1)cout << "No"<< endl;
    else cout << "Yes"<< endl;
}

