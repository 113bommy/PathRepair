n = int(input())
x = list(map(int, input().split()))
setx = set(x)
pw = []
for i in range(32):
    pw.append(2**i)
ans = None
for i in range(n):
    for j in range(32):
        a = (x[i]-pw[j]) in setx
        b = (x[i]+pw[j]) in setx
        if a and b:
            print(3)
            print(x[i]-pw[j], x[i], x[i]+pw[j])
            exit(0)
        if a:
            ans = (x[i]-pw[j], x[i])
        elif b:
            ans = (x[i], x[i]+pw[j])
if ans is None:
    print(1)
    print(x[0])
else:
    print(2)
    print(*ans)