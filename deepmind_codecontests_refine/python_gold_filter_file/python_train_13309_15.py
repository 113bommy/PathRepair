N = int(input())
nums = list(map(int, input().split()))
ans = 10**14
for start in [-1, 1]:
  before = start
  cnt = 0
  sum_n = 0
  for num in nums:
    sum_n += num
    if before*sum_n >= 0:
      if before < 0:
        cnt += abs(1-sum_n)
        sum_n = 1
      else:
        cnt += abs(-1-sum_n)
        sum_n = -1
    before = sum_n
  ans = min(ans, cnt)
print(ans)