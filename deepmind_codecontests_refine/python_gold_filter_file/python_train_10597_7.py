I=lambda:map(int,input().split());n,m=I();d=[0]+[9**9]*2**n
while m:
 m-=1;a,_=I();s=sum(1<<c-1for c in I())
 for j in range(2**n):d[s|j]=min(d[s|j],d[j]+a)
print(d[-2]%9**9or-1)