t=int(input())
for i in range(t):
    NK=list(map(int,input().split()))
    n=NK[0]
    k=NK[1]
    sum=0
    for i in range(1,n):
        sum+=i
        if sum>=k:
            break
    str=["a" for j in range(n)]
    str[n-i-1]="b"
    diff=sum-k
    posi=i-diff
    str[n-posi]="b"
    str=''.join(str)
    print(str)