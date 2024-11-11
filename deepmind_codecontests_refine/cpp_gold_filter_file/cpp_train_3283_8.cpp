#include <bits/stdc++.h>
using namespace std;
map<string, set<string> > folder;
map<string, set<string> > files;
int main() {
  string S;
  while (cin >> S) {
    int N = S.size();
    vector<string> m_folder;
    for (int i = 0; i < N; i++)
      if (S[i] == '\\') m_folder.push_back(S.substr(0, i + 1));
    m_folder.push_back(S);
    int M = m_folder.size();
    for (int i = 0; i < M; i++) {
      for (int j = i + 1; j < M; j++) {
        if (j == M - 1)
          files[m_folder[i]].insert(m_folder[j]);
        else
          folder[m_folder[i]].insert(m_folder[j]);
      }
    }
  }
  int files_max = 0, folder_max = 0;
  map<string, set<string> >::iterator itr;
  for (itr = folder.begin(); itr != folder.end(); itr++) {
    if (itr->first.size() == 3) continue;
    folder_max = max(folder_max, (int)itr->second.size());
  }
  for (itr = files.begin(); itr != files.end(); itr++) {
    if (itr->first.size() == 3) continue;
    files_max = max(files_max, (int)itr->second.size());
  }
  cout << folder_max << ' ' << files_max << endl;
}
