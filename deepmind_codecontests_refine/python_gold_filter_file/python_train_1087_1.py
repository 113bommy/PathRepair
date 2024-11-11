import sys
input=sys.stdin.readline
n=int(input())
l=input().split()
li=[int(i) for i in l]
if(n==1):
    print(li[0])
    quit()
neg=[]
pos=[]
for i in range(n):
    if(li[i]>0):
        pos.append(li[i])
    elif(li[i]<0):
        neg.append(li[i])
if(len(pos)==0 and len(neg)<=1):
    print(0)
    quit()
for i in pos:
    print(i,end=" ")
neg.sort()
neg.reverse()
z=len(neg)
if(z%2==0):
    for i in neg:
        print(i,end=" ")
else:
    for i in range(1,z):
        print(neg[i],end=" ")
