def solve():
    n, k = map(int, input().split())
    for z in range(2):
        d = 2 - z
        ans = n - d*(k - 1)
        if ans%2 != d%2 or ans < 1:
            continue
        else:
            print("YES")
            for j in range(k):
                if j == 0:
                    print(ans, end = " ")
                else:
                    print(d, end = " ")
            print()
            return
    print("NO")
    
numcases = int(input())
for i in range(numcases):
    solve()