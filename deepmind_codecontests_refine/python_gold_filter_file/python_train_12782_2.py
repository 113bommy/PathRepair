import collections
n=int(input())
a=list(map(int,input().split()))
d=collections.Counter(a)
total=sum([(v-1)*v//2 for v in d.values()])
for x in a:
    print(total-d[x]+1)