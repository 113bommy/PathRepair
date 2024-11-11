u,v=map(int,input().split())
if(v==u and v==0):
    print(0)
elif(v==u):
    print("1")
    print(v)
elif(v<u or v%2!=u%2):
    print("-1")
else:
    d=(v-u)//2
    if(d&u):
        print(3)
        print(u,d,d)
    else:
        print(2)
        print(u+d,d)