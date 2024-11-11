from math import ceil

N, A, B = map(int, input().split())
h = []
for _ in range(N):
    h.append(int(input()))
    
left = 0
right = max(h)//B + 1

while right - left > 1:
    mid = (right + left) // 2
    c = sum([ceil((hi-mid*B)/(A-B)) for hi in h if hi > mid * B])
    if c > mid:
        left = mid
    else:
        right = mid
        
print(right)