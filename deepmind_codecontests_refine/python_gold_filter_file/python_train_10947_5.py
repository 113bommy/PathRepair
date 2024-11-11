t=int(input())
s=[]
for hfvjv in range(0,t):
    n=int(input())
    g=0
    k=[0,0,0]
    jj=[1,1,1]
    while k!=jj:
        if n%5==0:
            n=n//5
            g+=3
        else:
            k[2]=1
        if n%3==0:
            n=n//3
            g+=2
        else:
            k[1]=1
        if n%2==0:
            n=n//2
            g+=1
        else:
            k[0]=1
    if n==1:
        s.append(g)
    else:
        s.append(-1)
for i in s:
    print(i)
