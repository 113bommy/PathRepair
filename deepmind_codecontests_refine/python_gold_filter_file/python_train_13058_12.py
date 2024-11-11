import sys
n, t, c = map(int, sys.stdin.readline().split())
a = list(map(int, sys.stdin.readline().split()))
beg = 0
end = 0
ans = 0
for i in range(n):
  if a[i] > t:
    if end == i-1:
      ans += max(end-beg-c+2,0)
    beg = i+1
    end = i+1
  elif i == n-1:
    ans += max(n-beg-c+1,0)
  else:
    end = i
print(ans)
