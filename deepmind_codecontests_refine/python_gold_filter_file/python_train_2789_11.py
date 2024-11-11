a = int(input())
b = [int(i) for i in input().split()]
ans = 0
for i in range(a):
  ans += b[i]*(sum(b)-b[i])
print(ans//2)