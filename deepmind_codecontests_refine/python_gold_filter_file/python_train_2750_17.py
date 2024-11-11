n=int(input())
a=list(map(int,input().split()))
maxi=0
for i in a:
    z=a.count(i)
    if z>maxi:
        maxi=z
print(maxi,len(set(a)),sep=' ')
