t=int(input())
for z in range(t):
    x,y=map(int,input().split())
    a,b=map(int,input().split())
    sum1=0
    sum2=0
    sum1=(x+y)*a
    mini=min(x,y)
    maxi=max(x,y)
    sum2+=(maxi-mini)*a
    sum2+=mini*b
    print(min(sum1,sum2))