n = int(input())
a = [int(x) for x in input().split()]
ans = [0]*n

for i in range(n-1, -1, -1):
  ans[i] = sum(ans[i+i+1:n:i+1]) % 2 != a[i]

print(sum(ans))
for i in range(n):
  if ans[i] == 1:
    print(i+1)