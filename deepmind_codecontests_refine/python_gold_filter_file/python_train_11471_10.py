q=int(input())
for _ in range(q):
    n=int(input())
    a=list(map(int,input().split()))
    d={}
    for i in a:
        if i not in d:
            d[i]=1
        else:
            d[i]+=1
    s=sorted(d)
    l=len(s)
    if l%2==0:
        p=l//2
    else:
        p=l//2+1
    f=s[-1]*s[0]
    tag=True
    for i in range(p):
        if i==l-i-1:
            if s[i]*s[i]==f:
                if d[s[i]]%4==0:
                    pass
                else:
                    tag=False
                    break
            else:
                tag=False
                break
        elif s[i]*s[l-i-1]==f:
            if d[s[i]]==d[s[l-i-1]]:
                if d[s[i]]%2==0:
                    pass
                else:
                    tag=False
                    break
            
            else:
                tag=False
                break
        else:
            tag=False
            break
    if tag:
        print('YES')
    else:
        print('NO')
