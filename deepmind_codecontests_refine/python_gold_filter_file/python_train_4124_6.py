n=int(input())
l=list(map(int,input().split()))
li=[]
a=l[0]
c=1
q=0
for i in range(1,len(l)):
    if l[i]==a:
        e=i
        q=1
        break
    elif l[i]<a:
        e=i
        q=2
        break
    else:
        a=l[i]
        c=c+1
if c==len(l):
    print("YES")
else:
    li=l[e:]
    if q==1:
        c=1
        a=li[0]
        for i in range(1,len(li)):
            if li[i]==a and a==li[0]:
                c=c+1
            elif li[i]<a:
                c=c+1
                a=li[i]
            else:
                break
        if c==len(li):
            print("YES")
        else:
            print("NO")
    elif q==2:
        c=1
        a=li[0]
        for i in range(1,len(li)):
            if li[i]<a:
                c=c+1
                a=li[i]
            else:
                break
        if c==len(li):
            print("YES")
        else:
            print("NO")