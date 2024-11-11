def gcd(a,b):
    if a < b:
        a,b = b,a
    while(b != 0):
        a,b = b,a%b
    return a

n1,m1,q = map(int, input().split(" "))
hcf = gcd(n1,m1)
n = n1//hcf
m = m1//hcf
for ques in range(q):
    sx,sy,ex,ey = map(int, input().split(" "))
    sy -= 1
    ey -= 1
    if sx == 1:
        a = sy//n
    else:
        a = sy//m
    if ex == 1:
        b = ey//n
    else:
        b = ey//m
    if a == b:
        print("YES")
    else:
        print("NO")