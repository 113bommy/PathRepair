n , m = map(int, input().split())
f=0
for i in range(n , m+1):
    x = str(i)
    s = list(x)
    if len(s) == len(list(set(x))):
        print(i)
        f=1
        break
if f == 0:
    print(-1)