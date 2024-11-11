n,h=map(int,input().split())
ab=[[int(i) for i in input().split()] for _ in range(n)]
maxa=max(map(lambda x:x[0], ab))
ab.sort(key=lambda x:x[1],reverse=True)
ans=0
for a,b in ab:
  if b>maxa:
    h-=b
    ans+=1
  if h<=0:
    print(ans)
    exit(0)
print(ans+(h-1)//maxa+1)
