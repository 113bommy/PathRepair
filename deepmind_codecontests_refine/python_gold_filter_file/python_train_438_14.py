t=int(input())
for test in range(t):
    n=int(input())
    a1=list(map(int,input().split()))
    a=a1.copy()
    freq=set()
    f=True
    stay=set()
    for i in range(n):
        #if a[i]==0:
          #  stay.add(i)
        a[i]+=i
        if a[i]%n in freq:
            f=False
            break
        else:
            freq.add(a[i]%n)
        if a[i]%n in stay:
            f=False
            break
    if f:
        print("YES")
    else:
        print("NO")
        
