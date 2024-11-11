def f(d):
    k = d*(d-4) 
    return ((d)+(k**0.5))/(2),((d)-(k**0.5))/(2) 
for _ in range(int(input())):
    n = int(input())
    if n==1:
        print('N')
    else:
        a,b = f(n)
        if type(a)==float and type(b)==float:
            print('Y',a,b)
        else:
            print('N')