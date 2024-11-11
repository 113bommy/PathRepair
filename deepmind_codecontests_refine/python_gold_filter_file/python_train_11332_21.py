N, M = map(int, input().split())
A = []
B = []
for i in range(N):
    A.append(input())
for i in range(M):
    B.append(input())

for h in range(N-M+1):
    for w in range(N-M+1):
        if list(map(lambda x:x[w:w+M], A[h:h+M])) == B:
            print("Yes")
            exit()

print("No")
