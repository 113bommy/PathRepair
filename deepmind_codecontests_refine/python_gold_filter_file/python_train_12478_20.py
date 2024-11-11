n = int(input())
a, b = [input() for i in range(2)]
for i in range(n+1):
  if a[i:] == b[:n-i]:
    print(i + n)
    break