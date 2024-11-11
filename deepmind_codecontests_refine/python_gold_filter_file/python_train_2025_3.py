n=int(input())
l=list(map(int,input().split()))
count=0
for i in range(n):
    if l[i]<l[i-1]:
        count+=1
l2=sorted(l)
if l==l2:
    print(0)
else:
   if count>1:
       print(-1)
   else:
       for i in range(n):
        if l[i]>l[i+1]:
            print(n-i-1)
            break