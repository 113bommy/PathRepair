N=int(input())
a=[int(i)//400 for i in input().split()]
s=set()
r=0
for i in range(N):
    if a[i]>=8:
        r+=1
    else:
        s.add(a[i])
print("{0} {1}".format(max([1,len(s)]),len(s)+r))
