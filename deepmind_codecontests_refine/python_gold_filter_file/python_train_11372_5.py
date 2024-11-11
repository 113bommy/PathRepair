u,v=map(int,input().split())
if u>v or (v-u)%2:
    print(-1)
elif u==0 and v==0:
    print(0)
else:
    temp=(u + ((v-u)//2)) ^ ((v-u)//2)
    if u==v:
        print(1)
        print(u)
    elif temp==u:
        print(2)
        print(u + ((v-u)//2),((v-u)//2))
    else:
        print(3)
        print(((v-u)//2),((v-u)//2),u)

