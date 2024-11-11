n = int(input())
a = sorted([int(i) for i in input().split()])
cnt = 1
for ai in a:
  cnt *= ai
  if cnt > 10 ** 18:
    print(-1)
    exit()
print(cnt)