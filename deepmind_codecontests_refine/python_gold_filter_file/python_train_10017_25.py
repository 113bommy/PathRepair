n=int(input())
l=list(map(int,input().split()))
c1=0
c2=0
for i in l:
    if(i%2==0):
        c1+=1
    else:
        c2+=1
if(c2%2==0):
    print(c1)
else:
    print(c2)