n=int(input())
l=list(map(int,input().split()))
e=o=0
for i in l:
    if i%2==0:
        e+=1
    else:
        o+=1
if(o%2==0):
    print(e)
else:
    print(o)
