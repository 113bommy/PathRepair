t=int(input())
a=[]
def chk(a,b):
    if a==b:
        return 0
    if a>b:
        if a%2==0 and b%2==0:
            return 1
        elif a%2==1 and b%2==1:
            return 1
        elif a%2==0 or b%2==0:
            return 2
    elif a<b:
        if a%2==0 and b%2==0:
            return 2
        elif a%2==1 and b%2==1:
            return 2
        elif a%2==0 or b%2==0:
            return 1
        
for i in range(t):
    p,q=map(int,input().split()[:2])
    a.append(chk(p,q))
for i in a:
    print(i)