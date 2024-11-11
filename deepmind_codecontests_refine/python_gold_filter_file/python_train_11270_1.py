def f(P,n,j):
    if n<=2:
        return(-1)
    for i in range(n):
        if P[i] == n:
            break
    if i>0 and i<n-1:
        return([j,i+j,n-1+j])
    elif i == 0:
        P = P[1:]
        return(f(P,n-1,j+1))
    elif i == n-1:
        P = P[0:n-1]
        return(f(P,n-1,j))
t = int(input())
while(t>0):
    t = t-1
    n = int(input())
    p = input()
    P = list(map(int,list(p.split())))
    if f(P,n,0) == -1:
        print("NO")
    else:
        l = f(P,n,0)
        print("YES")
        print(l[0]+1,end=" ")
        print(l[1]+1,end=" ")
        print(l[2]+1)