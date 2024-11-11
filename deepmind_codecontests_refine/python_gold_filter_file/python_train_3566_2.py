t=int(input())
for _ in range(t):
    n=int(input())
    a=list(map(int,input().split()))

    even=[0]
    odd=[0]
    mino=0
    mine=0
    super=0
    i=1
    summer=a[0]
    while(i<n):
        if(i%2==0):
            summer+=a[i]
            olde=even[-1]
            super=max(super,-(a[i]-a[i-1])-mine+olde)
            mine=min(mine,-(a[i]-a[i-1])+olde)
            even.append(-(a[i]-a[i-1])+olde)
        else:
            oldo=odd[-1]
            super=max(super,a[i]-a[i-1]+oldo-mino)
            mino=min(mino,a[i]-a[i-1]+oldo)
            odd.append(a[i]-a[i-1]+oldo)

        
        i+=1

    print(summer+super)