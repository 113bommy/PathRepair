A = [int(input()) for i in range(5)]
B = [(10 - a % 10) % 10 for a in A]
print(sum(A) + sum(B) - max(B))
