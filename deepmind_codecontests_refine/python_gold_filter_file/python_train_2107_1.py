for _ in range(int(input())):
    n=int(input())
    s=list(map(int,input().split()))
    if len(set(s))==1:print(1);print('1 '*n)
    elif n%2==0:print(2);print('1 2 '*(n//2))
    else:
        ans=[]
        k=f=1
        for i in range(n):
            i1=(i-1)%n
            if f and s[i]==s[(i-1)%n]:ans.append(3-k);f=0
            else:ans.append(k);k=3-k
        if f:print(3);print('1 2 '*(n//2)+'3');continue
        else:print(2);print(*ans)