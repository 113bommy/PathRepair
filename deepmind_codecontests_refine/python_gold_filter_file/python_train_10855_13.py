import math
import collections
t=int(input())
for w in range(t):
    n=int(input())
    l=[int(i) for i in input().split()]
    s=sum(l)
    if(s%n!=0):
        print(-1)
    else:
        l1=[]
        c=0
        for i in range(1,n):
            if(l[i]%(i+1)!=0):
                c+=2
                l1.append((1,i+1,(i+1-l[i]%(i+1))))
                l1.append((i+1,1,(l[i]//(i+1))+1))
            else:
                c+=1
                l1.append((i+1,1,l[i]//(i+1)))
        print(c+n-1)
        for i in range(c):
            print(l1[i][0],l1[i][1],l1[i][2])
        for i in range(1,n):
            print(1,i+1,(s//n))