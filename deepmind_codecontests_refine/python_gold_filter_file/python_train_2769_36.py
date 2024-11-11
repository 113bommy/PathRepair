a,b=map(int,input().split())
if a<b:
    fa = 1
    for i in range(1, a + 1):
        fa = fa * i
    print(fa)
else:
    fb = 1
    for i in range(1, b+1):
        fb = fb*i
    print(fb)









