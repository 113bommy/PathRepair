a,b=map(int,input().split())
x=list(map(int,input().split()))
if a&1==1:
    ans=sum(x)&1
else:
    ans=x[-1]&1
if ans==0:
    print("even")
else:
    print("odd")