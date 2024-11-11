n=int(input())
p=list(map(int,input().split()))
d=0
for i in range(n):
    if p[i]!=i+1:
        d+=1
if d<=2:
    print("YES")
else:
    print("NO")