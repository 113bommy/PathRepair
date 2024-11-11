# import sys
# input=sys.stdin.readline

def fu(a,x):
    for i in range(x):
        a[i]=str((int(a[i])+1)%2)
    a[:x]=a[:x][::-1]
    
t=int(input())
for _ in range(t):
    n=int(input())
    a=list(input())
    b=list(input())
    c=[]
    for i in range(n):
        if a[n-i-1]!=b[n-i-1]:
            if a[0]==b[n-i-1]:
                c.append(n-i)
                fu(a,n-i)
                c.append(1)
                fu(a,1)
                c.append(n-i)
                fu(a,n-i)
            else:
                c.append(n-i)
                fu(a,n-i)
    print(len(c),*c)