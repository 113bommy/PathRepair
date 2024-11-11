import sys
 
R = lambda: list(map(int, input().split()))
 
def lcm(a,b):
    m = a*b
    while a != 0 and b != 0:
        if a > b:
            a %= b
        else:
            b %= a
    return m // (a+b)
 
n, p, w, d = R()
 
if (w*n)<p:
    print(-1)
    sys.exit()
    
if p==0:
    print(0, 0, n)
    sys.exit()
 
nod = lcm(w, d)
s_w = p//w
s_d = (p-s_w*w)//d
while ((p-s_w*w)%d!=0):
    s_w-=1
    s_d=(p-s_w*w)//d
    if(s_d > nod):
        print(-1)
        sys.exit()
if (s_w>=0)and(s_d>=0):
    print(s_w, s_d, n-(s_w+s_d))
else:
    print(-1)