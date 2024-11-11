n=int(input())
a=[]
for i in range(n):
    a.append(list(map(int, input().split())))
a.sort(key=lambda x:(-x[2],x[0]+x[1]))
for i in range(101):
    for j in range(101):
        ansh=[0]*n
        for k,(x,y,h) in enumerate(a):
            ansh[k]=h+abs(i-x)+abs(j-y)
            if h==0:ansh[k]=min([ansh[k],max(ansh[:k])])
        if len(set(ansh))==1:
             print(i,j,ansh[1])