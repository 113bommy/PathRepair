n=int(input())
s=1
a=1
if n==1:
    print("YES")
    exit()
for i in range(n):
    a+=1
    s+=a
    if s==n:
        print("YES")
        break
else:
    print("NO")
