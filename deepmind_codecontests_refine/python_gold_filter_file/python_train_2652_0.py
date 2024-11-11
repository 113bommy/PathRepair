m,t,r=input().split(' ')
m=int(m)
t=int(t)
r=int(r)
if t<r:
    input()
    need=-1
else:
    candles=[]
    need=r
    ghosts=input().split(' ')
    for i in range(r):
        candles.append(t-i)
    for i in range(len(ghosts)-1):
        dead=[]
        diff=int(ghosts[i+1])-int(ghosts[i])
        for j in range(len(candles)):
            candles[j]=max(candles[j]-diff,0)
            if candles[j] is 0:
                dead.append(candles[j])
        for candle in dead:
            candles.remove(0)
        need+=r-len(candles)
        for k in range(r-len(candles)):
            candles.append(t-k)
print(need)