from sys import stdin

def candy (a,b,c,d,e):
    if (e == 0): return a,b,c,d
    if (e == 1): return b,c-a,d,c
    if (e == 2): return c-a,d-b,c,d
    return (d-b, a, d, c)

def candy2 (a,b,c,e):
    if (e == 0): return a,b
    if (e ==1): return a, c-b

def main():
    '''
    Name: Kevin S. sanchez
    '''
    inp = stdin
    n, m, x, y, z, p = map(int, inp.readline().split())
    n, m, x, y, z = n+1, m+1, x%4 , y % 2, (4-z)%4

    for i in range (0,p):
        u, v = map(int, inp.readline().split())
        u, v, q, p =  candy(u,v,n,m,x)
        u,v = candy2(u,v,p,y)
        u,v,q,p = candy(u,v,q,p,z)

        print(u,v)

main()
    
