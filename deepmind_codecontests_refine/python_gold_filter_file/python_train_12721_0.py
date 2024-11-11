import math
test = int(input())
for _ in range(test):
    n = int(input())
    up=int(math.log(n, 3))
    used={}
    ans=0
    while(n>0):
        rem = int(math.log(n,3))
        if not used.get(rem, False):
            used[rem]=True
            n = n-3**rem
            ans+=3**rem
        else:
            don=False
            for i in range(rem+1, up):
                if not used.get(i, False):
                    ans+=3**i
                    for j in range(i-1, -1, -1):
                        if used.get(j, False):
                            ans-=3**j
                    don=True
                    break
            if not don:
                ans = 3**(up+1)
                don = True
            break
    print(ans)