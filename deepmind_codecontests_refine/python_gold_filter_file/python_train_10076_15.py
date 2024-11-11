n=int(input())
lists=list(map(int,input().split()))
 
mn=n+1
cnt=0
for li in lists:
  if mn>li:
    mn=li
    cnt+=1
print(cnt)