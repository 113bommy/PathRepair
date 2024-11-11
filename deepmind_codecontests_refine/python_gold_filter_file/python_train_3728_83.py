import sys
input = sys.stdin.readline

x, y, z, k = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
c = list(map(int, input().split()))

ab = [ai + bi for bi in b[:k] for ai in a[:k]]
ab.sort(reverse=True)

s = [ci + abi for abi in ab[:k] for ci in c[:k]]
s.sort(reverse=True)

for si in s[:k]:
    print(si)