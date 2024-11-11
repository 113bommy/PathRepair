
n, l = list(map(int, input().split()))
points=list(map(int, input().split()))
points.sort()
d=0
for i in range(n-1):
    cord1=points[i]
    a=i+1
    cord2=points[a]

    if cord2 -cord1 > 2*d :
        d= (cord2 -cord1)/2
    else:
        pass
d1=(points[0])-0
d2=l-(points[n-1])
ans=max(d1,d2,d)


print('%.9f'%(ans))

    
