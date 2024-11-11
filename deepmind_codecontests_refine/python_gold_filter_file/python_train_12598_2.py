q = int(input())
for i in range(q):
    a,b,c,d,e,f,g,h = [int(i) for i in input().split()]
    A = d-b
    B = c-a
    C = f-h
    D = e-g
    E = a*d-b*c
    F = e*h-f*g
    G = A*D-B*C
    print((E*D+F*B)/G,(E*C+F*A)/G)