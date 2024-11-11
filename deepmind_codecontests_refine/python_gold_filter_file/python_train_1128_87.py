N = int(input())
A = [0 for _ in range(9)]
for a in map(int,input().split()):
  A[min(a//400,8)]+=1
rate_num = 8-A[:-1].count(0)
print(max(1,rate_num), rate_num+A[-1])