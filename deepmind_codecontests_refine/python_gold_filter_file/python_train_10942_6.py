t = int(input())
b = list()
for i in range(t):
    a = list(map(int,input().split()))
    k = a[0] // a[3]
    d = (k//a[1])*a[2]
    b.append(k+d)
for i in range(t):
    print(b[i])