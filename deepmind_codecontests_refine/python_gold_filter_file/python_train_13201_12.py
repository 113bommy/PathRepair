N = int(input())
A, B = map(int,input().split())
P = [int(i) for i in input().split()]

a = sum(i<=A for i in P)
b = sum(A<i<=B for i in P)

print(min(a, b, N-a-b))
