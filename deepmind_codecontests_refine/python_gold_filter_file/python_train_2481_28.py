n=int(input());d,x=map(int,input().split());ans=x
for i in range(n):
  a=int(input())
  ans+=1+(d-1)//a
print(ans)