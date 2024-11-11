#include <iostream>
using namespace std;
int main(void)
{
    long long A,V,B,W,T,x,i,D,D2;
    cin >> A >> V;
    cin >> B >> W;
    cin >> T;
    D=abs(A-B);
    D2=(V-W)*T;
    puts(D<=D2?"YES":"NO");
    
}
