
n=int(input())  
l=list(map(int,input().split()))
l.sort()
flag=False
for i in range(n):
    if l[n-1]==l[n]:
        print("NO")
        flag=True
        break
if not flag:
    print("YES")