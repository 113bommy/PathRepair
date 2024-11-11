from math import ceil
l=[]
for _ in range(int(input())):
    x,y=map(int,input().split())
    l.append(x)
    l.append(y)
val= int(input())
low=0
ri=len(l)-1


for i in range(len(l)):
    if l[i]==val:
#         print(len(l)-i)
        print(ceil((len(l)-i)/2))
        break
    else:
        if l[i]<val and l[i+1]>val:
            print(ceil((len(l)-(i+1))/2))
            break