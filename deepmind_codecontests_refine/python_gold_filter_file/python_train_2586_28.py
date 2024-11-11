n = int(input())
a= [int(input()) for _ in range(n)]

count = 1
now = a[0]

while now != 2 and count < n:
  now = a[now-1]
  count += 1
print(count if count<n else -1)