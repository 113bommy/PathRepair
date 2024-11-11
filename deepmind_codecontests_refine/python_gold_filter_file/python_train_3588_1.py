ho,a=input(),input()
r=[];_h,_a=[0]*100,[0]*100
for _ in " "*int(input()):
    t,h,m,y=input().split();m=int(m)
    if h=='h':
        if y=='r':
            if _h[m]<2:r.append([ho,m,t]);_h[m]=3
        else:
            _h[m]+=1
            if _h[m]==2:r.append([ho,m,t]);_h[m]=3
    else:
        if y=='r':
            if _a[m]<2:r.append([a,m,t]);_a[m]=3
        else:
                _a[m]+=1
                if _a[m]==2:r.append([a,m,t]);_a[m]=3
for i in r:print(*i)