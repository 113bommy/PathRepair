N=int(input())
p=list(map(int,input().split()))
a=0
for i in range(N):
    if p[i]!=i+1:
        a+=1
if a<=2:
    print("YES")
else:
    print("NO")