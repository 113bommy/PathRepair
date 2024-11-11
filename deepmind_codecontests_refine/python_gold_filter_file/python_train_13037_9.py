import bisect
t=int(input())
for _ in range(t):
    n=int(input())
    A=list(map(int,input().split()))
    B={}
    for i in range(n):
        try:
            B[A[i]].append(i)
        except:
            B[A[i]]=[i]
    fa=0
    flag=0
    for i in B.keys():
        flag=flag+1
        lv=len(B[i])
        mv=lv
        for j in range(lv//2):
            for k in B.keys():
                if (k!=i):
                    c=((2*(j+1))+bisect.bisect(B[k],B[i][lv-j-1])-bisect.bisect(B[k],B[i][j]))
                    if (mv<c):
                        mv=c
        if (fa<mv):
            fa=mv

    if (flag==1):
        print(n)
    else:
        print(max(fa,1))
                    
                    
                    
                
            
        
    
