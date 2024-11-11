def compute_gcd(x, y):
    while(y):
       x, y = y, x%y
    return x
n,m,q = map(int,input().split())
aa = compute_gcd(n,m)
aa = (n*m)//aa
ang1 = aa//m
ang2 = aa//n
for i in range(q):
    l1 = []
    l2 = []
    x1,x2,y1,y2 = map(int,input().split())
    if x1!=y1:
        if x1 == 1:
            z = x2//ang1
            x = y2//ang2
            if x2%ang1 == 0:
                z = x2//ang1 - 1
            if y2%ang2 == 0:
                x = y2//ang2 - 1
        else:
            z = x2//ang2
            x = y2//ang1
            if x2%ang2 == 0:
                z = x2//ang2 - 1
            if y2%ang1 == 0:
                x = y2//ang1 - 1
        if z == x:
            print("YES")
        else:
            print("NO")
    else:
        if x1 == 1:
            z = x2//ang1
            x = y2//ang1
            if x2%ang1 == 0:
                z = x2//ang1 - 1
            if y2%ang1 == 0:
                x = y2//ang1 - 1
        else:
            z = x2//ang2
            x = y2//ang2
            if x2%ang2 == 0:
                z = x2//ang2 - 1
            if y2%ang2 == 0:
                x = y2//ang2 - 1
        if z == x:
            print("YES")
        else:
            print("NO")
            
            
            
                
                
            
    
    
