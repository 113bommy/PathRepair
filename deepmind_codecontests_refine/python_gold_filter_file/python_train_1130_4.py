from bisect import bisect_left, bisect_right
N = int(input())
x = list(map(int, input().split()))
L = int(input())
n = N.bit_length()+1
next_hotel = [[0]*n for _ in range(N)]
for i in range(N):
    index = bisect_right(x, x[i]+L)-1
    if index == i:
        next_hotel[i][0] = N
    else:
        next_hotel[i][0] = index
for i in range(1, n):
    for j in range(N):
        if next_hotel[j][i-1]<N:
            index = next_hotel[next_hotel[j][i-1]][i-1]
            if index == j:
                next_hotel[j][i] = N
            else:
                next_hotel[j][i] = index
        else:
            next_hotel[j][i] = N
def count(a, b):
    if a>b:
        a, b = b, a
    res = 0
    for i in range(n):
        if a >= b:
            return  res
        c = max(0, bisect_left(next_hotel[a], b)-1)
        a = next_hotel[a][c]
        res+=2**c
Q = int(input())
for _ in range(Q):
    a, b = map(int, input().split())
    print(count(a-1, b-1))