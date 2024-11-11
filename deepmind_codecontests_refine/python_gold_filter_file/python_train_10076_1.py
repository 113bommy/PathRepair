n=int(input())
a=list(map(int,input().split()))
b=[]
mx=10**10
cnt=0
for i in a:
  mx=min(mx,i)
  if mx>=i:
    cnt+=1
print(cnt)
