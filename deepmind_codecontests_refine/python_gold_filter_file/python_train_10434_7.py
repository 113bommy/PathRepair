def power(g,z):
    w = g
    c = 0
    while w>=z:
        c+=1
        w = w//z
    return c
for i in range(int(input())):
    a = 0
    n,k = map(int,input().split())
    l = list(map(int,input().split()))
    l1 = []
    for i in l:
        if i == 0:
            continue
        j = i
        while j>0:
            q = power(j,k)
            if q in l1:
                a+=1
                break
            j = j-(k**q)
            l1.append(q)
        if j!=0:
            a+=1
            break
    if a == 0:
        print("YES")
    else:
        print("NO")
        
            
        
        
