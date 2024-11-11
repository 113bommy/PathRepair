n,a,b=map(int,input().split())

if (b-a)%2==0:
  ans=(b-a)//2
else:
  ans=min((a+b)//2,(2*(n+1)-(a+b))//2)
  
print(ans)