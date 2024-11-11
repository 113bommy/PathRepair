import io, os
#input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
R = lambda : map(int, input().split())
k = int(input())
print(3, 3)
inf = 2 << 16
print(inf + k, k, k)
print(inf, inf, inf + k)
print(inf, inf, k)
