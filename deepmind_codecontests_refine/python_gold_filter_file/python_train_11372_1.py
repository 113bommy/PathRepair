u,v = map(int,input().split())
if u > v or (u%2 != v%2):
    print(-1)
    exit()

if u == v:
    if u == 0:
        #print(1)
        print(0)
        exit()

    else:
        print(1)
        print(u)
        exit()

x = (v-u)//2
if (x&u):
    print(3)
    print(u,x,x)

else:
    print(2)
    print(u+x,x)