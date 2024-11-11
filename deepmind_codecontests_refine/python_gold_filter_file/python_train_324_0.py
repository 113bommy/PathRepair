def solve():
    n=int(input())
    l=list(map(int,input().split()))
    l.sort()
    ct=[l[x] for x in range(0,n) if l[x]%2==0]
    ct2=[l[x] for x in range(0,n) if l[x]%2!=0]
    if(len(ct)>len(ct2)):
        del(ct[-1])
        for i in range(len(ct)-len(ct2),len(ct)):
            ct[i]=0
        print(sum(ct))
    elif(len(ct)<len(ct2)):
        del(ct2[-1])
        for i in range(len(ct2)-len(ct),len(ct2)):
            ct2[i]=0
        print(sum(ct2))
    else:
        print(0)
solve()