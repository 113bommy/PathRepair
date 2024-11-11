n=int(input())
for i in range(n):
    f=0
    k=int(input())
    l=list(map(int,input().split()))
    l.sort()
    for p in range(k-1):
        if l[p]==l[p+1]:
            f=1
            print("0")
            break
    m=abs(l[0]-l[1])
    if f!=1:
        for q in range(k-1):
            if(abs(l[q]-l[q+1])<m):
                m=abs(l[q]-l[q+1])
        print(m)