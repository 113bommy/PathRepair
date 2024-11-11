h1,h2 = map(int,input().split())
a,b = map(int,input().split())
if h1+a*8 >= h2:
    print(0)
    exit(0)
if a<=b:
    print(-1)
    exit(0)
mn = 12*(a-b)
h = h2-h1-8*a
print(-((-h)//mn))