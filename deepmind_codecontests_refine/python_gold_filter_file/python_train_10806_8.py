N = int(input())
Vs = map(int, input().split())
Cs = map(int, input().split())

print(sum([ v - c for v, c in zip(Vs, Cs) if v >= c ]))
