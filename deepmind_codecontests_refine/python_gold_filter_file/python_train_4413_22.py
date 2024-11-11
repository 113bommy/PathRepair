n=input()
n=int(n)
a=[int(i) for i in input().split()]
s,t=[int(i) for i in input().split()]
r=None
if(abs(s-t)==1):
    if(s<t):
        r=min(a[s-1],(sum(a)-a[s-1]))
    else:
        r = min(a[s - 2], (sum(a) - a[s - 2]))
else:
    if(s<t):
        y=0
        i=s-1
        while i< (t-1):
            y+=a[i]
            i+=1
        r=min(y,sum(a)-y)
    else:
        y=0
        i=t-1
        while i< (s-1):
            y+=a[i]
            i+=1
        r=min(y,sum(a)-y)
print(r)
