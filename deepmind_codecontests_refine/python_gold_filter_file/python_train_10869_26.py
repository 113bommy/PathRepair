n = int(input())
a = [int(_) for _ in input().split()]
b = [a[n-1]]+a
b.pop()
t = abs(b[0]-b[1])
for i in range(n-1):
    t = min(t,abs(a[i]-a[i+1]))
if abs(b[1]-b[0])==t:
    print(n,1)
else:
    for i in range(n-1):
        if a[i+1]+t==a[i] or a[i]+t==a[i+1]:
            print(i+1,i+2)
            break
