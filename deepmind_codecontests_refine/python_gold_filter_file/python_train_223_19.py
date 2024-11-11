T = int(input())
 
for _ in range(T):
    a, b, n = map(int,input().split())
    n %= 3
    if n == 2: print(a^b)
    elif n == 0: print(a)
    else: print(b)