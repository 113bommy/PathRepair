def check(a,b):
    c=0
    if b-a>=2:
        c+=1
    else:
        c=0
    return c
n=int(input())
l=[]
while n>0:
    n-=1
    a,b=map(int,input().split())
    c=check(a,b)
    l.append(c)
print(sum(l))
    
