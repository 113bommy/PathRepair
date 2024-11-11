import sys
input = sys.stdin.readline

def main():
  h, w = map(int, input().split())
  A = [list(map(int, input().split())) for _ in range(h)]
  B = [list(map(int, input().split())) for _ in range(h)]
  M = 80*(h+w)
  dp = [[0]*w for i in range(h)]
  d = abs(A[0][0] - B[0][0])
  mask = (1 << (2*M)) - 1
  dp[0][0] |= 1 << (M-d)
  dp[0][0] |= 1 << (M+d)
  for i in range(h):
    for j in range(w):
      d = abs(A[i][j] - B[i][j])
      if i:
        dp[i][j] |= (dp[i-1][j] << d) & mask
        dp[i][j] |= dp[i-1][j] >> d
      if j:
        dp[i][j] |= (dp[i][j-1] << d) & mask
        dp[i][j] |= dp[i][j-1] >> d
  t = dp[-1][-1] >> M
  ans = (t & (-t)).bit_length() - 1
  print(ans)
  
if __name__ == "__main__":
  main()