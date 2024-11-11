def gcd(x, y): 
    while(y): 
        x, y = y, x % y 
    return x 

n, m, q = [int(i) for i in input().split()]
gc = gcd(n, m)
kp = (n*m) // gc
bat1 = kp//n
bat2 = kp//m
gc2 = gcd(bat1, bat2)
kp2 = (bat1*bat2)//gc2
b1 = kp2//bat1
b2 = kp2//bat2
for i in range(q):
    a,b,c,d = [int(i) for i in input().split()]
    if(a==1 and c==1):
        if (b-1)//b1 == (d-1)//b1:
            print("YES")
        else:
            print("NO")
    if(a==1 and c==2):
        a,c = c,a
        b,d = d,b
    if(a==2 and c==1):
        if (b-1)//b2 == (d-1)//b1:
            print("YES")
        else:
            print("NO")
    if(a==2 and c==2):
        if (b-1)//b2 == (d-1)//b2:
            print("YES")
        else:
            print("NO")
