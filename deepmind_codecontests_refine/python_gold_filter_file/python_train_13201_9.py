n = int(input())
a,b = map(int, input().split())
p = list(map(int, input().split()))

cnt=[0,0,0]
for poi in p:
  if poi <= a:
  	cnt[0]+=1
  elif poi <=b:
    cnt[1]+=1
  else:
    cnt[2]+=1
print(min(cnt))