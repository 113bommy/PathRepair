import math
n=int(input())
l=list(map(int,input().split()))
l.sort(reverse=True)
for i in l:
    if(i>=0):
        p=int(math.sqrt(i))
        if(p*p!=i):
            print(i)
            break
    else:
        print(i)
        break
        