#include <bits/stdc++.h>
using namespace std;
int dr[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dc[] = {-1, 1, -2, 2, -2, 2, -1, 1};
vector<pair<long long, long long> > vertical, horiz;
vector<pair<long long, long long> >::iterator it0, it1;
int main() {
  long long tc, t = 0;
  horiz.push_back(make_pair(1, 1));
  horiz.push_back(make_pair(1, 3));
  vertical.push_back(make_pair(3, 1));
  vertical.push_back(make_pair(3, 2));
  vertical.push_back(make_pair(3, 3));
  vertical.push_back(make_pair(3, 4));
  string arr;
  cin >> arr;
  long long ln = arr.size();
  it0 = vertical.begin();
  it1 = horiz.begin();
  for (long long i = 0; i < ln; i++) {
    if (arr[i] == '1') {
      cout << it1->first << " " << it1->second << endl;
      it1++;
      if (it1 == horiz.end()) it1 = horiz.begin();
    } else {
      cout << it0->first << " " << it0->second << endl;
      it1++;
      if (it0 == vertical.end()) it0 = vertical.begin();
    }
  }
}
