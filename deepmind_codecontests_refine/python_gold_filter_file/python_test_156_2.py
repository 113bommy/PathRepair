import math
for _ in range(int(input())):
    n,k = map(int,input().split())
    A = list(map(int,input().split()))
    s = sum(A)
    if s <=k:
        print(0)
    else:
        A.sort()
        diff = s-k
        ans = s-k
        s = 0
        for i in range(n-1,0,-1):
            s += A[i]
            if s-(n-i)*A[0] >= diff:
                calc = 0
            
            else:
                #print((diff-s+(n-i)*A[0])/(n-i))
                calc = math.ceil((diff-s+(n-i)*A[0])/(n-i+1))
            
            ans = min(ans,calc+n-i)
        print(ans)