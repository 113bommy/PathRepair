n=int(input())
a=list(map(int,input().split()))
c=0
if sum(a)%2==0:b=0
else:b=1
for i in a:
    if i%2==b:c+=1
print(c)