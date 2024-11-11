t = int(input())
for i in range(t):
    #a = n er coin
    #b = 1 er coin
    a,b,n,S = map(int, input().split())
    
    need_a = S//n
    
    if a >= need_a:
        S = S % n
    else:
        S = S - (n*a)
    
    if b >= S:
        print("YES")
    else:
        print("NO")