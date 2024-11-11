N = input()
A, B = map(int, input().split())
P = list(map(int, input().split()))

q1 = len([p for p in P if p <= A])
q2 = len([p for p in P if A < p and p <= B])
q3 = len([p for p in P if p > B])

print(min(q1, q2, q3))
