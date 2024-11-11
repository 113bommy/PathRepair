#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[100009];
int prep[100009];
int sumPrepDays;
int lastExamDayForSubject[100009];
bool emptyDays[100009];
int accEmptyDays[100009];
vector<int> orderedExams;
bool ok(int numDays) {
  orderedExams.clear();
  for (int i = 1; i <= numDays; i++) {
    lastExamDayForSubject[i] = -1;
    emptyDays[i] = true;
  }
  for (int i = numDays; i > 0; i--)
    if (arr[i] != 0 && lastExamDayForSubject[arr[i]] < 0) {
      lastExamDayForSubject[arr[i]] = i;
      orderedExams.push_back(arr[i]);
      emptyDays[i] = false;
    }
  accEmptyDays[0] = 0;
  for (int i = 1; i <= numDays; i++) {
    if (emptyDays[i])
      accEmptyDays[i] = accEmptyDays[i - 1] + 1;
    else
      accEmptyDays[i] = accEmptyDays[i - 1];
  }
  if (accEmptyDays[numDays] < sumPrepDays) return false;
  int usedEmptyDays = 0;
  for (int i = orderedExams.size() - 1; i >= 0; i--) {
    int examnum = orderedExams[i];
    int remainningDays =
        accEmptyDays[lastExamDayForSubject[examnum]] - usedEmptyDays;
    if (remainningDays < prep[examnum]) return false;
    usedEmptyDays += prep[examnum];
  }
  if (usedEmptyDays != sumPrepDays) return false;
  return true;
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
  sumPrepDays = 0;
  for (int i = 1; i <= m; i++) {
    scanf("%d", &prep[i]);
    sumPrepDays += prep[i];
  }
  int l = 1, r = n, minn = INT_MAX, mid, counter = 50;
  while (l <= r) {
    mid = (l + r) / 2;
    if (ok(mid)) {
      r = mid;
      minn = min(minn, mid);
    } else
      l = mid + 1;
    if (!counter) break;
    counter--;
  }
  if (minn == INT_MAX)
    printf("-1\n");
  else
    printf("%d\n", minn);
  return 0;
}
