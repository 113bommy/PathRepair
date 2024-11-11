#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
/*void toBinary(ll x){


    char s[100];
    ltoa(x , s , 2);
    cout << s << endl;
}*/

bool comp(int a , int b){

    return (a &-a)  > (b & -b) ;
}
const int N = 1e5 + 5  ;
int a[N];
int main()
{



    // 1010
    int n ;
    cin >> n ;
    int xo = 0 ;
    for(int i =0 ; i < n ; i ++){
        cin >> a[i];
        xo ^= a[i];
    }
    int res = 0 ;
    sort(a , a + n , comp );
    for(int i =0 ; i < n ; i ++)
    {
          int x = a[i];
          if(( x & -x ) & xo){
                xo = (xo ^ a[i]);
                xo ^= (a[i] -1);
                res ++ ;
          }

    }
    if(!xo){
        cout << res << endl;
    }else {
        puts("-1");
    }



    return 0;
}
