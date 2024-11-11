n = int(input())
for i in range(n):
  t, x, y = map(int, input().split())
  if t < (x+y) or (t+x+y)%2==1:
    print("No")
    exit()

print("Yes")
