def Csum(a):
    b,c=[0],0
    for i in range(len(a)):
        c+=a[i]
        b.append(c)
    return b

n=int(input())
a=list(map(int,input().split()))
s=Csum(a)
su=sum(a)
b=1
c=0
for i in range(n+1):
    c+=b
    b-=a[i]
    if b<=0:
        if i==n and b==0:
            break
        print(-1)
        exit()
    b=min(b*2,su-s[i+1])
print(c)