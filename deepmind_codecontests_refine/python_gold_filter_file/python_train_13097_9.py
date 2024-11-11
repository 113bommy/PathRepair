n = int(input())
a, b, c = 0, 0, 0

for i in range(n):
  x, y, z = map(int, input().split())
  a, b, c = x+max(b,c), y+max(a,c), z+max(a,b)
print(max(a,b,c))