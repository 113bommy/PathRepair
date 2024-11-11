t = int(input())

for _ in range(t):
    a, b, n, m = map(int, input().split())
    if a + b < n + m:
        print('No')
    else:
        diff = abs(a-b)
        diff += m - n
        if diff <= a + b - n - m:
            print('Yes')
        else:
            print('No')


        
