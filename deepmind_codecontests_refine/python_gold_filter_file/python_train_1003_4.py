n = int(input())
a = [int(i) for i in input().split()]
b = [abs(a[i+1]-a[i]) for i in range(n-1)]
f = 1
for i in b:
    if(i>=2):
        f = 0
        break
if(f):
    print("YES")
else:
    print("NO")