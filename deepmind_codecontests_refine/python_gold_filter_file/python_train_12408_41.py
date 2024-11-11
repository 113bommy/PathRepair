l,r=list(map(int,input().split()))
def func(x):
    l1=[]
    while(x):
        ans=x%10
        if ans in l1:
            return 0
        else:
            l1.append(ans)
            x//=10
    return 1
for i in range(l,r+1):
    if(func(i)):
        print(i)
        break
else:
    print(-1)