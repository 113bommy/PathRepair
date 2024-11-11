k=int(input())
n=input()
x=''
v=''
b=0
lst=[]
lst1=[]
if(n.count(n[0])==len(n) and len(n)==k):
    print(n)
else:
    for i in n:
        if(i not in lst1):
            x=x+i
            if(n.count(i)%k==0):
                lst.append(n.count(i))
            else:
                b=b+1
        lst1.append(i)
    if(b==0):
        for j in x:
            v+=(j*(n.count(j)//k))
        print(v*k)
    else:
        print(-1)
