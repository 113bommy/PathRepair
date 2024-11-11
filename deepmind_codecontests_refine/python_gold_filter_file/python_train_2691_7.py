import math
N, A, B = map(int, input().split())
H = [int(input()) for i in range(N)]
    
def f(x):
    s = sum([math.ceil(max(0, h - x * B) / (A - B)) for h in H])
    if s <= x:
        return True
    else:
        return False
    
l = 0
r = 10 ** 9 + 7
while r - l > 1:
    m = (l + r) // 2
    if f(m):
        r = m
    else:
        l = m
    # print(r, l, m)
        
print(r)