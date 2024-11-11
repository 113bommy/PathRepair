t=int(input())
for i in range(t):
    #n,m = map(int, input().strip().split(' '))
    n=int(input())
    lst = list(map(int, input().strip().split(' ')))
    m=200000
    l=[0]*(n+1)
    for j in range(n):
        if l[lst[j]]!=0:
            if j-l[lst[j]]+2<m:
                m=j-l[lst[j]]+2
        l[lst[j]]=j+1
        #print(l)
    if m==200000:
        print(-1)
    else:
        print(m)
        
        
    
   