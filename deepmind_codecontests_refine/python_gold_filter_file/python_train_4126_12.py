import sys
n=int(input())
k=str(n)
m=[]
cnt=0
if(len(k)==1):
    if n%2==0:
        print(1)
        print(n//2)
    else:
        print(0)
    sys.exit()
for i in range(max(n-9*len(k),0),n):
    l=str(i)
    sm=0
    for j in l:sm+=int(j)
    if i+sm==n:
        cnt+=1
        m.append(i)
print(cnt)
print(*m)
    
