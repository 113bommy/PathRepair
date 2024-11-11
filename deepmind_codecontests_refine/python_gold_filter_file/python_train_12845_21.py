s=input().split()

n=int(s[0])
k=int(s[1])
ans=[]
a=0
for i in range(n):
    for j in range(i+1,n):
        a+=1

if(a<=k):
    print("no solution")

else:
    for i in range(-10**9,-10**9+n):
        print("0 "+str(i))
