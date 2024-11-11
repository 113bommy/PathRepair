import heapq
def heapu(counted, heee, f, d, e):
    for i in range(f, d, e):
        while (len(heee) > 0 and (heee[0][0] * -1) > a[i]):
            counted[heee[0][1]] = (i - heee[0][1])
            heapq.heappop(heee)
        heapq.heappush(heee, [a[i] * -1, i])
    return counted

for t in range(int(input())):
    n=int(input())
    a=list(map(int,input().split()))
    he=[[-a[0],0]]
    plus=0
    f_counted=[]
    b_counted=[]
    for i in range(n):
        b_counted.append(plus)
        plus-=1
    plus=n-1
    for i in range(n):
        f_counted.append(plus)
        plus-=1
    counted_f=heapu(f_counted,he,1,n-1,1)
    hee=[[-a[n-1],n-1]]
    counted_b=heapu(b_counted,hee,n-1,0,-1)
    f_maxi=[]
    maxi=0
    for i in range(0,n):
        maxi=max(maxi,a[i])
        f_maxi.append(maxi)
    b_maxi=[]
    maxi=0
    for i in range(n-1,-1,-1):
        maxi=max(maxi,a[i])
        b_maxi.append(maxi)
    b_maxi=b_maxi[::-1]
    x, y, z = -1, -1, -1
    flag=1
    for i in range(1,n-1):
        x, y, z = -1, -1, -1
        if(a[i]==b_maxi[i+counted_f[i]]):
            z=n-i-f_counted[i]
        elif(a[i]==b_maxi[i+counted_f[i]-1] and counted_f[i]>1):
            z=n-i-f_counted[i]+1
        if(a[i]==f_maxi[i+counted_b[i]]):
            x=i+b_counted[i]+1
        elif(a[i]==f_maxi[i+counted_b[i]+1] and counted_b[i]<-1):
            x=i+b_counted[i]+1+1
        y=n-x-z
        if(x>-1 and z>-1):
            flag=0
            break
    if(flag==0):
        print("YES")
        print(x,y,z)
    else:
        print("NO")
