//洛谷P1919
#include<bits/stdc++.h>
#include<complex>
using namespace std;

const int N=3e6+10;
const long double PI=acos(-1);
typedef complex<long double> Complex;
struct FastFourierTransform  {
    Complex omega [N], omegaInverse [N] ;
    void init ( int n )  {
        for ( int i = 0 ; i < n ; ++ i )  {
            omega [i] = Complex ( cos ( 2 * PI / n * i), sin ( 2 * PI / n * i ) ) ;
            omegaInverse [i] = conj(omega [i]);
        }
    }
    void transform ( Complex *a, int n, const Complex* omega ) {
        for ( int i = 0, j = 0 ; i < n ; ++ i )  {
            if ( i > j )  swap ( a [i], a [j] ) ;
                for( int l = n >> 1 ; ( j ^= l ) < l ; l >>= 1 ) ;
	    }
        for ( int l = 2 ; l <= n ; l <<= 1 )  {
            int m = l >> 1;
            for ( Complex *p = a ; p != a + n ; p += l )
                for ( int i = 0 ; i < m ; ++ i )  {
                    Complex t = omega [n / l * i] * p [m + i] ;
                    p [m + i] = p [i] - t ;
                    p [i] += t ;
                }
        }
    }
    void dft ( Complex *a, int n )  {
        transform ( a, n, omega ) ;
    }
    void idft ( Complex *a, int n )  {//逆变换
        transform ( a, n, omegaInverse ) ;
        for ( int i = 0 ; i < n ; ++ i ) a [i] /= n ;
    }
} fft ;
Complex a[N];

typedef long long ll;
ll P=200003;
ll c[N];
int idx[200003];
int Pow[200003];

int main(){
    ll tmp=1;
    for(int i=0;i<=P-2;++i){
        idx[tmp]=i;
        Pow[i]=tmp;
        tmp=tmp*2%P;
    }
    int n;
    scanf("%d",&n);
    ll ans=0;
    for(int i=0;i<n;++i){
        scanf("%lld",c+i);
        if(c[i]==0)continue;
        a[idx[c[i]]]+=Complex(1,0),ans-=c[i]*c[i]%P;
    }
    
    tmp=1;
    n=2*P;
    while(tmp<n)tmp<<=1;
    n=tmp;
    fft.init(n);
    fft.dft(a,n);
    for(int i=0;i<n;++i)a[i]*=a[i];
    fft.idft(a,n);
    
    for(int i=0;i<n;++i){
        ans+=(ll)(a[i].real()+0.5)*Pow[i%(P-1)];
    }
        
    ans/=2;
    printf("%lld",ans);
    return 0;
}
/*
3
2019 2020 200002
*/