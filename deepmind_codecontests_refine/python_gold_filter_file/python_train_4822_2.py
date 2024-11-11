t = int(input())
def solve():
    n,k = map(int, input().split())
    if(n == 1 and n == k):
        print(-1)
        return
    low = 2
    high = n
    arr = [1]
    for i in range(k):
        if(low >= high):
            print("-1")
            return
        arr.append(high)
        arr.append(low)
        low += 1
        high -= 1
    for i in range(low, high + 1):
        arr.append(i)
    print(*arr)
for i in range(t):
    solve()