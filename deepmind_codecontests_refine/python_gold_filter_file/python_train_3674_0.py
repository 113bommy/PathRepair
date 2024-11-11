def fun(s,s1):
    n=len(s)
    m=len(s1)
    
    t=[[0 for i in range(m+1)]for j in range(n+1)]
    
    for i in range(m+1):
        t[i][0]=1
    
    for i in range(1,n+1):
        for j in range(1,m+1):
            if s[i-1]==s1[j-1]:
                t[i][j]=t[i-1][j-1]+t[i-1][j]
            else:
                t[i][j]=t[i-1][j]
                
    return t[n][m]


for _ in range(int(input())):
    n,q=map(int,input().split())
    s=input()
    for i in range(q):
        l,r=map(int,input().split())
        st=False
        if s[l-1] in s[:l-1]:
            st=True
        if s[r-1] in s[r:]:
            st=True
        if st:
            print("YES")
        else:
            print("NO")
    