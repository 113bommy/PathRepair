m,d = map(int,input().split())
cnt = 0
for i in range(d+1):
  d10,d1 = i//10,i%10
  if d10 >= 2 and d1 >= 2 and d1 * d10 <= m:
    cnt += 1
print(cnt)