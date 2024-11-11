def ss(a,d,n):

    return n*(2*a+(n-1)*d)//2


T = int(input())

for loop in range(T):

    n,l,r = map(int,input().split())

    ans = []

    lb = 0
    rb = n-1

    while rb - lb != 1:

        m = (lb+rb) // 2

        if ss(2*n-2,-2,m) >= l:
            rb = m
        else:
            lb = m

    BB = rb
    ind = ss(2*n-2,-2,rb-1) + 1
    inind = BB+1
    state = 0
    
    while ind <= r:

        #print (ind,BB,inind)

        now = 0
        if state == 0:
            now = BB
            state = 1
        else:
            now = inind
            inind += 1
            state = 0

            if inind == n+1:
                BB += 1
                inind = BB+1
        
        if ind == ss(2*n-2,-2,n-1) + 1:
            ans.append(1)
            break
        if ind >= l:
            ans.append(now)
        ind += 1
        
    print (*ans)
