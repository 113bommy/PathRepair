aa=int(input())
for i in range(aa):
    temp=0
    x,y=map(int,input().split())
    if(x<y):
        temp=x
        x=y
        y=temp
    if(x==y):
        print('0 0')
        continue
    else:
        g_c_d= abs(x-y)
        z=x%g_c_d
        mini=min(z,g_c_d-z)
    print(g_c_d,mini)