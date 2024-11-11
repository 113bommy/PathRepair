for _ in range(int(input())):
    n=int(input())
    s=map(int,input().split())
    s=list(s)
    #for i,x in enumerate(s):
    i=0
    while i!=n:
        if s[i]<i:
            break
        i+=1
    
    #for j in range(n-1,-1,-1):
    j=n-1
    while j!=-1:
        if s[j]<n-1-j:
            break
        j-=1
    i-=1
    j+=1
    #print(i,j)
    if i<j:
        print('No')
    else:
        print('Yes')