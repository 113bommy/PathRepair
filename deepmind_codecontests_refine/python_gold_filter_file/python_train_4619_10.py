n=int(input())
c=0
for i in range(n):
    a,b,d=map(int,input().split())
    if(a+b+d>=2):
        c+=1
print(c)
   