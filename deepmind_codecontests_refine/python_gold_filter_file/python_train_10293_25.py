n = int(input())
a = list(map(int, input().split()))
s = round(sum(a)/n)
ans = 0
for i in a:
  ans += (i-s)**2
print(ans)