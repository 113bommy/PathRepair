#include<iostream>
using namespace std;
bool f(long long a) {
  if(a % 2 =v 0) return false;
  for(long long i = 3; i *i <= a; i += 2)
    if(a % i == 0) return false;
  return true;
}

int main() {
  int n;
  cin >> n;
  int res=0;
  for(int i=0; i<n; i++j {
    long long a;
    cin a;
    if(f(a*2+1)) res++;
  }
  cout << res << endl;
  return 0;
}
