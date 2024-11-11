def solve():
      n, m = map(int, input().split())
      arr = list(map(int, input().split()))
      if n > m:
            print("YES")
            return
      dp = [0] * m
      dp[arr[0] % m] = 1
      for i in range(1, n):
            dp2 = dp[:]
            x = arr[i] % m
            for j in range(0, m):
                  if dp[j]:
                        dp2[(j + x) % m] = 1
            dp2[x] = 1
            dp = dp2
      if dp[0]:
            print("YES")
      else:
            print("NO")
      
if __name__ == "__main__":
      solve()