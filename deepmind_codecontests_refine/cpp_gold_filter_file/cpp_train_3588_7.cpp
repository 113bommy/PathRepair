#include <bits/stdc++.h>
using namespace std;
class CFoulData {
 public:
  const static int MAX_PLAY_NUM = 100;
  const static int MAX_NAME_LEN = 100;

 public:
  CFoulData() {
    memset(bOutPlayer[0], 0, sizeof(bool) * MAX_PLAY_NUM);
    memset(bOutPlayer[1], 0, sizeof(bool) * MAX_PLAY_NUM);
    memset(cFoulCnt[0], 0, sizeof(char) * MAX_PLAY_NUM);
    memset(cFoulCnt[1], 0, sizeof(char) * MAX_PLAY_NUM);
  }
  void process();

 private:
  bool bOutPlayer[2][MAX_PLAY_NUM];
  char cFoulCnt[2][MAX_PLAY_NUM];
  char szTeamName[2][MAX_NAME_LEN];
};
void CFoulData::process() {
  int iNumOfFouls = 0;
  scanf("%s%s%d", szTeamName[0], szTeamName[1], &iNumOfFouls);
  int mintutes, player_num;
  char cWhichTeam, type;
  for (int ri = 0; ri < iNumOfFouls; ++ri) {
    scanf("%d %c %d %c", &mintutes, &cWhichTeam, &player_num, &type);
    int idx__ = cWhichTeam == 'a' ? 1 : 0;
    if (type == 'r') {
      if (bOutPlayer[idx__][player_num]) continue;
      printf("%s %d %d\n", szTeamName[idx__], player_num, mintutes);
      bOutPlayer[idx__][player_num] = true;
    } else {
      if (cFoulCnt[idx__][player_num] == 0)
        ++cFoulCnt[idx__][player_num];
      else {
        if (bOutPlayer[idx__][player_num]) continue;
        printf("%s %d %d\n", szTeamName[idx__], player_num, mintutes);
        bOutPlayer[idx__][player_num] = true;
      }
    }
  }
}
int main() {
  CFoulData().process();
  return EXIT_SUCCESS;
}
