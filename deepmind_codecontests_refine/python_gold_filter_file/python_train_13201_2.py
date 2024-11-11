from bisect import *
N = int(input())
A, B = map(int, input().split())
P = list(map(int, input().split()))
P.sort()
a = bisect_right(P, A)
b = bisect_right(P, B)-a
c = N-b-a
print(min(a, b, c))