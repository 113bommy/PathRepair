#include<iostream>
#include<algorithm>
using namespace std;
int main(void)
{
    long long n,a,b,c=0;
    cin >> n >> a >> b;
    cout << max(c,b*(n-1)+a-(a*(n-1)+b)+1);
    return 0;
}
