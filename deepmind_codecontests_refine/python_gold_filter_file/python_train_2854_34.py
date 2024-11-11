n=int(input())
a=list(map(int,input().split()))
if n<3:
    print(n)
else:
    x=[2]
    cnt=2
    for i in range(2,n):
        if a[i]==a[i-1]+a[i-2]:
            cnt+=1
        else:
            x.append(cnt)
            cnt=2
    x.append(cnt)
    print(max(x))