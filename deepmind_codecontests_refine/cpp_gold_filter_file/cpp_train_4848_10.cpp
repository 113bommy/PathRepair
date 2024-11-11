#include <bits/stdc++.h>
using namespace std;
int CorrespondToPattern(const string& pattern, const string& compare) {
  if (pattern.size() != compare.size()) return 1;
  for (int i = 0; i < pattern.size(); ++i) {
    if (pattern[i] != compare[i] && pattern[i] != '?') return 1;
  }
  return 0;
}
string CompareString(const string& first, const string& second) {
  string pattern{""};
  for (int i = 0; i < first.size(); ++i) {
    pattern += (first[i] == second[i]) ? string(1, first[i]) : "?";
  }
  return pattern;
}
int main() {
  int lines, lines_to_be_deleted;
  scanf("%d%d", &lines, &lines_to_be_deleted);
  vector<string> files(lines);
  for (int line = 0; line < lines; ++line) {
    cin >> files[line];
  }
  vector<int> to_be_deleted_indexes(lines_to_be_deleted);
  for (int i = 0; i < lines_to_be_deleted; ++i)
    scanf("%d", &to_be_deleted_indexes[i]);
  string pattern = files[to_be_deleted_indexes[0] - 1];
  int pattern_length = pattern.size();
  for (int i = 1; i < to_be_deleted_indexes.size(); ++i) {
    pattern = CompareString(pattern, files[to_be_deleted_indexes[i] - 1]);
    if (pattern_length != files[to_be_deleted_indexes[i] - 1].size()) {
      cout << "No" << endl;
      return 0;
    }
  }
  for (const auto& index : to_be_deleted_indexes) files[index - 1] = "";
  int unique_pattern = 1;
  for (const auto& file : files) {
    unique_pattern &= CorrespondToPattern(pattern, file);
  }
  if (!unique_pattern) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl << pattern << endl;
  }
  return 0;
}
