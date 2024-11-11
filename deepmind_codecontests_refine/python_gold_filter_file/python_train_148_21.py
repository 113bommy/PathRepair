a=list(map(int,input().split()))
s=0
for i in a:
    s+=i

if s%5==0 and s>0:
    print(s//5)
else:
    print(-1)
    
