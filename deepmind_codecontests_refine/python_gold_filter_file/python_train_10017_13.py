n=int(input())
a=list(map(int, input().rstrip().split()))
o=0
e=0
for i in range(n):
    if a[i]%2==0:
        e+=1
    else:
        o+=1
if sum(a)%2==1:
    print(o)
else:
    print(e)