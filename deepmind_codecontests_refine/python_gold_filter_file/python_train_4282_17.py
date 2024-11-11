import math
n, s =list(map(int, input().split()))
keg=list(map(int, input().split()))
keg.sort()
ans=-1
while(s>0):
    cmin=keg[0]
    if(keg[0]<keg[-1]):
        for q in range(len(keg)):
            if(s<1):
                break
            if(keg[q]>cmin):
                if(s>keg[q]-cmin):
                    s-=keg[q]-cmin
                    keg[q]=cmin
                else:
                    keg[q]-=s
                    s=0
    else:
        keg[0]-=math.ceil(s/len(keg))
        s=0
if(keg[0]<0):
    print(-1)
else:
    print(keg[0])


