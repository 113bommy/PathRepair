#include <bits/stdc++.h>
using namespace std;
set<char> st;
set<char>::iterator it;
map<long long, long long> mp;
map<long long, long long>::iterator itr;
vector<string> vrat;
vector<string> vwom_chi;
vector<string> vmen;
int arr[3][3], a[3][3];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL), cout.tie(NULL);
  long long a, b, l, arr[1000], s = -1;
  cin >> a >> b;
  for (int i = 0; i < b; i++) cin >> arr[i];
  for (int i = 0; i < a; i++) {
    int r = (arr[i] % a);
    if (mp[r] > 0) {
      cout << i + 1 << endl;
      s = 0;
      break;
    }
    mp[r]++;
  }
  if (s == -1) cout << "-1" << endl;
}
