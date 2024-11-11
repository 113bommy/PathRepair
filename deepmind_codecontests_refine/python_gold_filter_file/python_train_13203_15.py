n = int(input())
for _ in range(n):
  dt, dx, dy = list(map(int, input().split()))
  if( (dx + dy) > dt ):
    print("No")
    exit()
  if((dx + dy) % 2 != dt % 2):
    print("No")
    exit()
print("Yes")
