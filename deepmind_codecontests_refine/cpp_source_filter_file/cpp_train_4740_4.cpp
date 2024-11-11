#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int main() {
  std::ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  ;
  string s;
  set<string> bf;
  for (int i = 0; i < 10; i++)
    for (int j = i + 1; j < 10; j++)
      for (int k = j + 1; k < 10; k++)
        for (int l = k + 1; l < 10; l++) {
          string temp =
              to_string(i) + to_string(j) + to_string(k) + to_string(l);
          bf.insert(temp);
          while (next_permutation(temp.begin(), temp.end())) bf.insert(temp);
        }
  int n;
  cin >> n;
  vector<string> nums(n);
  vector<pair<int, int>> BandC(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i] >> BandC[i].first >> BandC[i].second;
  }
  for (auto i = bf.begin(); i != bf.end();) {
    for (int j = 0, inPlace = 0, outPlace = 0; j < n;
         j++, inPlace = outPlace = 0) {
      for (int k = 0; k < 4; k++)
        if (nums[j][k] == (*i)[k]) inPlace++;
      for (int k = 0; k < 4; k++)
        for (int l = 0; l < 4; l++)
          if (l != k)
            if (nums[j][l] == (*i)[k]) outPlace++;
      if (inPlace != BandC[j].first || outPlace < BandC[j].second) {
        auto temp = i;
        i++;
        bf.erase(temp);
        break;
      } else if (j == n - 1)
        i++;
    }
  }
  if (!bf.size())
    cout << "Incorrect data\n";
  else if (bf.size() == 1)
    cout << *bf.begin() << endl;
  else
    cout << "Need more data\n";
  return 0;
}
