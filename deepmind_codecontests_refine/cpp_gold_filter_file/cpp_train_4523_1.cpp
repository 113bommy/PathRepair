#include <bits/stdc++.h>
using namespace std;
int main() {
  int size, k, result = -1e9, tmp = 0, s1, s2;
  cin >> size >> k;
  vector<int> array(size);
  for (int i = 0; i < size; i++) cin >> array[i];
  for (int i = 0; i < size; i++)
    for (int j = i; j < size; j++) {
      vector<int> tmp1, tmp2;
      for (int z = 0; z < size; z++)
        if (z >= i && z <= j)
          tmp1.push_back(array[z]), tmp += array[z];
        else
          tmp2.push_back(array[z]);
      sort(tmp1.begin(), tmp1.end()),
          sort(tmp2.begin(), tmp2.end(), greater<int>()), s1 = tmp1.size(),
                                                          s2 = tmp2.size();
      for (int z = 0; z < k; z++)
        (z < s1 && z < s2)
            ? ((tmp1[z] < tmp2[z]) ? (tmp -= tmp1[z], tmp += tmp2[z]) : 0)
            : 0;
      result < tmp ? result = tmp : 0, tmp = 0;
    }
  cout << result << endl;
  return 0;
}
