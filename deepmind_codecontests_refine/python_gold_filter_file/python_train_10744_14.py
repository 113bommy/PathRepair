t=int(input())
for _ in range(t):
    a=input().split()
    a=[int(x) for x in a]
    a.sort(reverse=True)
    l=len(a)
    maxx=a[0]
    maxx2=sum(a[1:l])
    a=a[2:l]
    if(maxx-1<=maxx2):
        print("Yes")
    else:
        print("No")
