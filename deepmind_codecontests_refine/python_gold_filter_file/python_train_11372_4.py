u,v=map(int,input().split())
if (u-v)%2!=0 or u>v:
    print(-1)
elif u==0 and v==0:
    print(0)
elif u==v:
    print(1)
    print(u)
elif ((u)&((v-u)//2))==0:
    print(2)
    print((u+v)//2,(v-u)//2)
else:
    print(3)
    print(u,(v-u)//2,(v-u)//2)