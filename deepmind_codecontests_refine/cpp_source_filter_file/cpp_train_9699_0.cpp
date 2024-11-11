#include <bits/stdc++.h>
using namespace std;
int main(int argc, char* argv[]) {
  cin.sync_with_stdio(false);
  cout.sync_with_stdio(false);
  int N, M;
  cin >> N >> M;
  vector<string> data(N);
  for (int i = 0; i < N; i++) cin >> data[i];
  vector<string> data_rev(M, string(N, '.'));
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++) data_rev[j][i] = data[i][j];
  vector<vector<int> > starts(M);
  for (int i = 0; i < M; i++) {
    starts[i].push_back(0);
    for (int j = 1; j < N; j++) {
      if (data_rev[i][j] != data_rev[i][j - 1]) {
        starts[i].push_back(j);
      }
    }
    starts[i].push_back(N);
  }
  vector<vector<short> > already_counted(starts.size());
  for (size_t i = 0; i < starts.size(); i++) {
    already_counted[i] = vector<short>(starts[i].size(), (short)0);
  }
  long long main_res = 0LL;
  for (int i = 0; i < M; i++) {
    for (size_t j = 3; j < starts[i].size(); j++) {
      if (!already_counted[i][j - 1]) {
        int h = starts[i][j - 1] - starts[i][j - 2];
        if (h <= starts[i][j] - starts[i][j - 1] &&
            h <= starts[i][j - 2] - starts[i][j - 3]) {
          int i_after_last = i + 1;
          while (i_after_last < M) {
            int j_absolute_1 = starts[i][j - 1];
            int j_absolute_2 = starts[i][j - 2];
            int j_absolute_3 = starts[i][j - 3];
            if (data_rev[i][j_absolute_1] !=
                    data_rev[i_after_last][j_absolute_1] ||
                data_rev[i][j_absolute_2] !=
                    data_rev[i_after_last][j_absolute_2] ||
                data_rev[i][j_absolute_3] !=
                    data_rev[i_after_last][j_absolute_3]) {
              break;
            }
            int idx_ =
                lower_bound(starts[i_after_last].begin(),
                            starts[i_after_last].end(), starts[i][j - 1]) -
                starts[i_after_last].begin();
            if (idx_ < starts[i_after_last].size() &&
                starts[i_after_last][idx_] == starts[i][j - 1] &&
                starts[i_after_last][idx_ - 1] == starts[i][j - 2] &&
                h <= starts[i_after_last][idx_ - 1] -
                         starts[i_after_last][idx_ - 2] &&
                h <= starts[i_after_last][idx_ + 1] -
                         starts[i_after_last][idx_]) {
              already_counted[i_after_last][idx_] = (short)1;
              i_after_last++;
            } else
              break;
          }
          int sz = (i_after_last - i);
          main_res += (sz * (sz + 1)) / 2;
        }
      }
    }
  }
  cout << main_res << endl;
  return 0;
}
