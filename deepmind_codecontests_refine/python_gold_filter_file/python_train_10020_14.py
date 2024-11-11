"""
Author: Q.E.D
Time: 2020-05-31 10:22:01
"""
T = int(input())
for _ in range(T):    
    n, x = list(map(int, input().split()))
    m = 0
    for i in range(n - 1):
        u, v = list(map(int, input().split()))
        if u == x or v == x:
            m += 1
    if m <= 1:
        ans = 'Ayush'
    else:
        ans = 'Ayush' if (n - 2) % 2 == 0 else 'Ashish'
    print(ans)