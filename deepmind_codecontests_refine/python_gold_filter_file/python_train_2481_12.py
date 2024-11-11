n = int(input())
d,x = map(int, input().split())
for i in range(n):
  x += 1 + (d - 1) // int(input())
print(x)