n=int(input())
l=[]
for i in range(n):
    j=input()
    a,b=tuple(map(int,j.split()))
    l.append((a,b))
for k in range(len(l)):
    a=l[k][0]
    b=l[k][1]
    for m in range(a,b+1):
            if m*2<=b: 
                print(m,m*2)
                break