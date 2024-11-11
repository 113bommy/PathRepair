r,g,b,n=map(int,input().split())

cnt=0
for R in range(n//r+1):
 for G in range((n-r*R)//g+1):
  num=n-R*r-G*g
  if num>=0 and num%b==0:
   cnt+=1
print(cnt)