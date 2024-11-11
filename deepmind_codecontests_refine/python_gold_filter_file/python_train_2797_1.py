"""
0-1ナップザック
dp[i][j]...i個目までの宝で重さjの時の価値の最大
wi = wlst[i]...i個目の重さ
vi = vlst[i]...i個目の価値
dp[i][j] = max(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - wi] + vi)  (wi <= j)
dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])                          (wi >  j)
"""


def main():
  case = 0

  while True:
    w = int(input())
    if not w:
      break
  
    case += 1
  
    n = int(input())
  
    vlst = [0]
    wlst = [0]
  
    for _ in range(n):
      vin, win = map(int, input().split(","))
      vlst.append(vin)
      wlst.append(win)

    dp = [[0 for _ in range(w + 1)] for _ in range(n + 1)]
    
    for i in range(1, n + 1):
      vi, wi = vlst[i], wlst[i]
      dpi = dp[i]
      dpim = dp[i - 1]
      for j in range(1, w + 1):
        if j >= wi:
          dpi[j] = max(dpim[j], dpi[j - 1], dpim[j - wi] + vi)
        else:
          dpi[j] = max(dpim[j], dpi[j - 1])
  
    print("Case " + str(case) + ":")
    print(dp[n][w])

    for i in range(w, -1, -1):
      if dp[n][i] != dp[n][w]:
        print(i + 1)
        break

main()
