
main=[]    
for _ in range(1):
    n=int(input())
    g=1
    ans=[]
    while(n>3):
       ans=ans+[g]*((n+1)//2)
       g=g*2
       n=n//2
    if n==1:
        ans.append(g)
    if n==2:
        ans.extend([g,g*2])
    if n==3:
        ans.extend([g,g,g*3])
    ans.sort()
    print(*ans)