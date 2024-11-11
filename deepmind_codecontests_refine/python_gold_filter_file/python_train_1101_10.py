b,q,l,m = (int(v) for v in input().split())
a, ok, N = [int(v) for v in input().split()], [], 64
while abs(b) <= l and N:
    N -= 1
    if b not in a: ok.append(b)
    b = b*q

print(len(ok) if len(ok)<31 else 'inf')
