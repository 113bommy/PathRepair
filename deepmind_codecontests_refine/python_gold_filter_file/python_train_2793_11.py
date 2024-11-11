K = int(input())
A = list(map(int, input().split()))
ma = 2
mi = 2
for a in reversed(A):
    ma = a * (ma // a + 1) - 1
    mi = a * -(-mi // a)
    if mi > ma:
        print(-1)
        break
else:
    print(mi, ma)