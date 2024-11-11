n = int(input())
li = list(map(int, input().split()))
m =10000000000000
for i in range(n-1):
    if(abs(li[i] - li[i+1]) < m):
        m = abs(li[i] - li[i+1])
        x = i; y = x+1
if(abs(li[0]-li[-1]) < m):
    print(1, n)
else:
    print(x+1, y+1)