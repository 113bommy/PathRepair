n = int(input())
p = list(map(int,input().split()))
q = list(map(int,input().split()))
p.remove(p[0])
q.remove(q[0])
p = list(set(p).union(set(q)))
if (0 in p):
    p.remove(0)
if (len(p) == n):
    print("I become the guy.")
else:
    print("Oh, my keyboard!")