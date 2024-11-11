#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

using C = complex<double>;
double pi = acos(-1.0);

void FFT(vector<C>& A, bool inv) {
 int N=A.size();
 for(int i=0,j=0; j<N; j++){
  if(i<j) swap(A[i],A[j]);
  for(int k=N>>1; k>(i^=k); k>>=1);
 }
 for(int i=1; i<N; i<<=1){
  C q = C(cos(pi/i),sin(pi/i)*(inv?1.0:-1.0));
  C qj = C(1.0,0.0);
  rep(j,i){
   for(int k=j; k<N; k+=i*2){
    C l=A[k], r=A[k+i]*qj;
    A[k]=l+r;
    A[k+i]=l-r;
   }
   qj*=q;
  }
 }
 if(inv) rep(i,N) A[i]/=N;
}

vector<C> CONV(const vector<C>& A,const vector<C>& B) {
 int Z=1; while(Z<A.size()+B.size()) Z<<=1;
 vector<C> Ax(Z),Bx(Z);
 rep(i,Z) Ax[i]=Bx[i]=0;
 rep(i,A.size()) Ax[i]=A[i];
 rep(i,B.size()) Bx[i]=B[i];
 FFT(Ax,false);
 FFT(Bx,false);
 rep(i,Z) Ax[i]*=Bx[i];
 FFT(Ax,true);
 return move(v);
}

const ULL M=200003;
int N;
ULL I[M];
vector<C> A;
vector<C> V;

int main() {
 scanf("%d", &N);
 for (int i=0,j=1; i<M-1; i++,j=j*2%M) I[j]=i;
 A.resize(M-1);

 ULL sq=0;
 rep(i, N) {
  int a; scanf("%d",&a);
  if(a) A[I[a]] += C(1.0,0.0);
  sq += (ULL)a*a%M;
 }
 V = CONV(A,A);

 ULL ans=0;
 for (int i=0,j=1; i<V.size(); i++,j=j*2%M)
  ans += (ULL)(V[i].real()+0.5)*j;
 ans = (ans-sq)/2;

 cout<<ans<<endl;

 return 0;
}
