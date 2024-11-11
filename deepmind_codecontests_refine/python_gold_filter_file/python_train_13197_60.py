n = int(input())
li_a = list(map(int, input().split()))
sum_ = 0
li_a.sort()
for i in range(1, n):
  sum_ += li_a[n-1-i//2]
print(sum_)
