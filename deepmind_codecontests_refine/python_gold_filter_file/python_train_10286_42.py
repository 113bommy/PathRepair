n=int(input())
p=list(map(int,input().split(" ")))
c=0
for i in range(n):
    if p[i]!=i+1:
        c+=1
if c<=2:
    print("YES")
else:
    print("NO")