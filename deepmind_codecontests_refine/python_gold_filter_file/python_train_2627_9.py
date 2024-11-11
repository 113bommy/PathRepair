n = int(input())
ans=[]
a = list(map(int,input().split()))
ans.append(a[0])
past = ans[-1]
big = a[0]
for i in range(1,n):
    if(a[i]>=0):
        ans.append(a[i]+past)
        past = ans[-1]
        if(ans[-1]) > big:
            big = ans[-1]
    elif a[i]<0 and a[i] < big:
        ans.append(big+a[i])
    else:
        ans.append(0)
print(*ans)

