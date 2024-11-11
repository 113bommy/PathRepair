n=int(input())
q=n
name=[]
l1=[]
l2=[]
l3=[]
for i in range(n):
    p,s=input().split()
    name.append(s)
    p=int(p)
    r0=0
    r1=0
    r2=0
    for i in range(p):
        s=input()
        k=int(s[0])
        l=int(s[1])
        m=int(s[3])
        n=int(s[4])
        o=int(s[6])
        p=int(s[7])
        if(k==l and l==m and m==n and n==o and o==p):
            r0=r0+1
        elif(k>l and l>m and m>n and n>o and o>p):
            r1=r1+1
        else:
            r2=r2+1
    l1.append(r0)
    l2.append(r1)
    l3.append(r2)
x=max(l1)
y=max(l2)
z=max(l3)
a=0
print('If you want to call a taxi, you should call:',end=" ")
for i in range(q):
    if(l1[i]==x and a==0):
        print(name[i],end="")
        a=1
    elif(l1[i]==x and a==1):
        print(", "+name[i],end="")
print(".")
print('If you want to order a pizza, you should call:',end=" ")
a=0
for i in range(q):
    if(l2[i]==y and a==0):
        print(name[i],end="")
        a=1
    elif(l2[i]==y and a==1):
        print(", "+name[i],end="")
print(".")
print('If you want to go to a cafe with a wonderful girl, you should call:',end=" ")
a=0
for i in range(q):
    if(l3[i]==z and a==0):
        print(name[i],end="")
        a=1
    elif(l3[i]==z and a==1):
        print(", "+name[i],end="")
print(".")