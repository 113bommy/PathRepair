X, Y, A, B, C = map(int, input().split())
P = list(map(int, input().split()))
Q = list(map(int, input().split()))
R = list(map(int, input().split()))
 
R += sorted(P)[-X:]
R += sorted(Q)[-Y:]
ans = sum(sorted(R)[-(X+Y):])
print(ans)