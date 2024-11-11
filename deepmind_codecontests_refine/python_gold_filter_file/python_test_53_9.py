for _ in range(int(input())):
    n,k = map(str,input().split())
    n = int(n)
    A = input()
    ok = False
    for i in range(n):
        if A[i] !=k:
            ok = True
    if not ok:
        print(0)
            
    else:
        for x in range(2,n+1):
            zz = True
            i = x
            while x <= n:
                if A[x-1] !=k:
                    zz = False
                    break
                x +=i
                
            if zz:
                print(1)
                print(i)
                break
        if not zz:
            print(2)
            print(n,n-1)
        