q = int(input())
for i in range(q):
    a,b,c,d,e,f,g,h = [int(i) for i in input().split()]
    A = a*d-b*c
    B = e*h-f*g
    C = d-b
    D = c-a
    E = f-h
    F = e-g
    det = C*F - D*E
    print((A*F + B*D)/det,(A*E + B*C)/det)