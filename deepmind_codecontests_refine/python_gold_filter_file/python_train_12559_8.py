t=int(input())
for i in range(t):
    n=int(input())
    tm=0
    ans=""
    for j in range(n):
        l,r=map(int,input().split())
        if tm>r:
            ans+="0"+" "
        else:
            if tm<=l:
                tm=l+1
            else:
                tm+=1
            ans+=str(tm-1)+" "
    print(ans)
