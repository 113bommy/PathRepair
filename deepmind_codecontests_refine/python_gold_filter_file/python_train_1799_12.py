max=31
l=[1,6,28]
j=1
for i in range(3,max):
    x=l[i-1]-pow(2,i-1)
    for j in range(((i-1)*2)+1,(2*i)+1):
        x+=pow(2,j)
    l.append(x)
#print(l)
for _ in range(int(input())):
    n=int(input())
    if(n==1):
        print(1)
        continue
    c=0
    t=0
    i=0
    while(t<=n):
        t+=l[i]
        i+=1
    print(i-1)