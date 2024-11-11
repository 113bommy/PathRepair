x,y=[int(t) for t in input().split()]
num=y
if y==0 and x!=1 or y>9*x:
    print('-1 -1')
    exit()
else:
    mini=0
    maxi=0
    n=0
    while y>9:
        mini+=10**n*9
        y-=9
        n+=1
    mini=mini+(y-1)*10**n+10**(x-1)
    n=x-1
    y=num
    while y>9:
        maxi+=10**n*9
        y-=9
        n-=1
    maxi=maxi+y*10**n
print(mini,maxi)

    
