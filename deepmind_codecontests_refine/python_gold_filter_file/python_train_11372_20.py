
u,v=map(int,input().split())
if u>v:
    print(-1)
elif (v-u)%2!=0:
    print(-1)
else:
    d=(v-u)//2
    if (u+d)^d==u:
        if d==0 and (u+d)==0:
            print(0)
        elif d==0 or (u+d)==0:
            print(1)
            print(max(d,u+d))
        else:
            print(2)
            print(d, u+d)
    else:
        print(3)
        print(u,d,d)