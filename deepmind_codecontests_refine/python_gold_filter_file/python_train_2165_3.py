n = int(input())
a = list(map(int,input().split()))
k = 1

for i in a:
    if k == i:
        k += 1

if k == 1:
    print(-1)
else:
    print(n-k+1)