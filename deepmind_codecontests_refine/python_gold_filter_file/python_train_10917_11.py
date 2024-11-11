import sys 
for e in sys.stdin:
    a, b = map(int, e.split())
    p = a * b
    while b:
        a, b = b, a%b
        pass
    print (a,p//a)
