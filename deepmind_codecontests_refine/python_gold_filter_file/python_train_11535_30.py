def run():
  ofs = 1000
  H, W = map(int, input().split())
  dp = [[0 for w in range(W)] for h in range(H)]
  a = [list(map(int, input().split())) for i in range(H)]
  b = [list(map(int, input().split())) for i in range(H)]
  c = [[abs(a[i][j] - b[i][j]) for j in range(W)] for i in range(H)]
  dp[0][0] = (1 << ofs + c[0][0]) | (1 << ofs - c[0][0])
  for h in range(1, H):
    dp[h][0] = (dp[h-1][0] << c[h][0]) | (dp[h-1][0] >> c[h][0])
  for w in range(1, W):
    dp[0][w] = (dp[0][w-1] << c[0][w]) | (dp[0][w-1] >> c[0][w])
  for h in range(1, H):
    for w in range(1, W):
      v = c[h][w]
      dp[h][w] = (dp[h-1][w] << v) | (dp[h-1][w] >> v)
      dp[h][w] |= (dp[h][w-1] << v) | (dp[h][w-1] >> v)
  s = list(bin(dp[-1][-1] >> ofs))
  for i in range(len(s)):
    if s[-1-i] == '1':
      print(i)
      break

if __name__ == '__main__':
  run()