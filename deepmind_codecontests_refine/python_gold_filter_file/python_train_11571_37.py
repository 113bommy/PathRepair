

n , v = map(int,input().split())
if n > v :
    t = v
    for i in range(2,(n-v)+1):
        t+=i
    print(t)
else:
    print(n-1)

