n = int(input())
a = [int(k) for k in input().split()]
cnt = 0
for i in range(n):
  if a[i] != i+1:cnt += 1
print("YES" if cnt <= 2 else "NO")