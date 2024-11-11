//
//  abc128_f.cpp
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef pair<LL, LL> PII;

int main () {
  int n;
  cin>>n;
  vector<int> seq(n);
  for (int i = 0; i < n; ++i) {
    cin>>seq[i];
  }
  
  long long ret = 0;
  for (int j = 1; j < n; ++j) {
    long long s = 0;
    for (int k = 0; j+k < n-1; k += j) {
      if (k>=(n-1-k) && (n-1) % j == 0) break;
      s += seq[k]+seq[n-1-k];
      ret = max(ret,s);
    }
  }
  
  cout << ret << endl;
  return 0;
}
