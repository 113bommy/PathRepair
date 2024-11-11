#include<bits/stdc++.h>

using namespace std;

int main(void){
  int K, T;
  cin >> K >> T;
  vector<int> a(T);
  for(int i = 0; i < T; i++) cin >> a[i];
  int m = *max_element(a.begin(), a.end());
  int s = accumulate(a.begin(), a.end(), 0) - m;
  cout << max(0, m - s - 1) << endl;
  return 0;
}
