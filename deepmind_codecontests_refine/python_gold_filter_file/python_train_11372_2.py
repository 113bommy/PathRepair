from sys import stdin,stdout
u,v=map(int,stdin.readline().split())
if u>v:
    print("-1")
elif u%2!=v%2:
    print("-1")
elif u==0 and v==0:
    print("0")
elif u==0:
    print(2)
    print(v//2,v//2)
elif u==v:
    print(1)
    print(u)
else:
    t=(v-u)//2
    if t&u!=0:
        print(3)
        print(u,t,t)
    else:
        print(2)
        print(u+t,t)