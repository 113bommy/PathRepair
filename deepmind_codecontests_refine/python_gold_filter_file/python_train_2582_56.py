a,b,c=map(int,input().split())
ans='No'
if a<c<b or b<c<a:
  ans='Yes'
print(ans)