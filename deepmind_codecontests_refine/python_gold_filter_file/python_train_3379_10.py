'''n=int(input())
v=n%7
if v==0:
    print((n//7)*2,(n//7)*2)
elif v==1:
    print((n//7)*2,(n//7)*2+1)
elif v==6:
    print((n//7)*2+1,(n//7)*2+2)
else:
    print((n//7)*2,(n//7)*2+2)
s=input()
t=input()
f='aeiou'
if len(s)!=len(t):
    print('No')
else:
    for i in range(len(s)):
        if f.find(s[i])==-1 and f.find(t[i])==-1:
            pass
        elif f.find(s[i])!=-1 and f.find(t[i])!=-1:
            pass
        else:
            print('No')
            break
    else:
        print('Yes')
m=int(input())
n=input().split()
for i in range(m):
    n[i]=int(n[i])
n.sort()
if len(n)%2==0:
    print(n[m//2-1])
else:
    print(n[m//2])
a=input()
b=input().split()
c=0
d=0
for i in b:
    c+=int(i)
x=c%2
if x==0:
    for i in b:
        if int(i)%2==0:
            d+=1
else:
    for i in b:
        if int(i)%2==1:
            d+=1
print(d)
n=int(input())
A=input().split()
m=int(input())
B=input().split()
for i in range(n):
    A[i]=int(A[i])
for i in range(m):
    B[i]=int(B[i])
A.sort()
B.sort()
print(int(A[n-1]),int(B[m-1]))
n=input()
c=1
t=0
for i in n:
    if i in'AEIOUY':
        if t<c:
            t=c
        c=1
    else:
        c+=1
if t<c:
    t=c
print(t)
a=int(input())
b=int(input())
c=int(input())
n=[]
n.append(a)
n.append(b//2)
n.append(c//4)
n.sort()
print(n[0]*7)
from math import ceil
a=[int(i) for i in input().split()]
b=[int(i) for i in input().split()]
s=0
d=0
for i in range(a[0]):
    if ceil(b[i]/a[1])>=s:
        s=ceil(b[i]/a[1])
        d=i
print(d+1)
f=input().split()
m=int(f[1])
n=int(f[0])
d=0
if (m/n)%2!=0 and (m/n)%3!=0 and m!=n:
    print(-1)
else:
    while m!=n:
        if m/n%2==0:
            m/=2
            d+=1
        elif m/n%3==0:
            m/=3
            d+=1
        else:
            print(-1)
            break
    else:
        print(d)
from math import sqrt
n=input().split()
s=int(n[0])
d=int(n[1])
v=int(input())
c=111111111111111111111111111111111111111111111111111111111111111111111111
for i in range(v):
    i=input().split()
    e=sqrt((int(i[0])-s)**2+(int(i[1])-d)**2)/int(i[2])
    if c>=e:
        c=e
        
print(c)
n=input()
s=set(n)
if len(s)%2==0:
    print("CHAT WITH HER!")
else:
    print('IGNORE HIM!')
n=int(input())
if n%4!=0 and n%7!=0 and n%47!=0 and n%74!=0 and n%44!=0 and n%77!=0 and n%444!=0 and n%447!=0 and n%474!=0 and n%477!=0 and n%744!=0 and n%747!=0 and n%774!=0 and n%777!=0:
    print('NO')
else:
    print('YES')
n=int(input())
while 0==0:
    n+=1
    if len(str(n))==len(set(str(n))):
        print(n)
        break'''
n=int(input())
a=input().split()
a=set(a[1:])
b=input().split()
b=set(b[1:])
c=a.union(b)
if len(c)==n:
    print("I become the guy.")
else:
    print("Oh, my keyboard!")


   
    
        

    


        


    
