#include <iostream>
#include <complex>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

//???????????¨
bool lt(const complex<double>& a,const complex<double>& b){
  return a.real()<b.real() || (a.real()==b.real() && a.imag()<b.imag());
}

double cp(complex<double> a, complex<double> b){
  return (conj(a)*b).imag();
}

int main(){
  int n;
  cin >> n;

  vector<complex<double> > v; 
  for(int i=0;i<n;i++){
    int x, y;
    cin >> x >> y;
    v.push_back(complex<double>(x+0.0,y+0.0));
  }

  sort(v.begin(),v.end(),lt);

  vector<complex<int> > u,b;
  u.push_back(v[0]);
  int i;
  for(i=0;i<n;i++){
    if(v[i].real()!=v[0].real()) break;
  }
  b.push_back(v[0]);
  b.push_back(v[i]);

  i=i+1;
  while(b.back()!=v.back()){
    b.push_back(v[i]);
    i++;

    int l=b.size();
    if(l<3) continue;
    if(cp(b[l-1]-b[l-2],b[l-3]-b[l-2])>=0) continue;
    else{
      b.pop_back();
      b.pop_back();
      i--;
    }
  }
  
  i=1;
  while(u.back()!=v.back()){
    u.push_back(v[i]);
    i++;

    int l=u.size();
    if(l<3) continue;
    if(cp(u[l-1]-u[l-2],u[l-3]-u[l-2])<=0) continue;
    else{
      u.pop_back();
      u.pop_back();
      i--;
    }
  }

  double min=b[0].imag(), index=0;
  for(int i=1;i<b.size();i++){
    if(b[i].imag()<min){
      min=b[i].imag();
      index=i;
    }
  }

  cout << (b.size()+u.size()-2) << endl;
  for(int i=index;i<b.size();i++)
    cout << noshowpoint << b[i].real() << ' ' << b[i].imag() << endl;
  for(int i=u.size()-2;i>=1;i--)
    cout << noshowpoint << u[i].real() << ' ' << u[i].imag() << endl;
  for(int i=0;i<index;i++)
    cout << noshowpoint << b[i].real() << ' ' << b[i].imag() << endl;

  return 0;
}