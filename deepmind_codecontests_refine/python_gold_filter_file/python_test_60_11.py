from collections import defaultdict, Counter

for _ in range(int(input())):
    n=int(input())

    a=[int(x)  for x in input().split()]
    s=sum(a)
    if (2*s%(n)!=0):
        print(0)
    else:
        an=0
        x=(2*s )//(n)
        #print(x)
        z=Counter(a)
        if x%2==0:
            an+=(z[x//2]*(z[x//2]-1))
        for i in a:
            if x-i!=i:
                if z[x-i]:
                    an+=z[x-i]

        print(an//2)