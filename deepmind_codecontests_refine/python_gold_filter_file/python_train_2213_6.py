# from bisect import bisect_left
# TC = int(input())

# for tc in range(TC):
N, M = map(int, input().split())
X, K, Y = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

# print(N, M, X, K, Y, A, B)

AB = [0 for _ in range(len(B) + 2)]
AS = AB.copy()
AS[0] = 0
AB[0] = -1
i = 0
j = 0
l = 0
li = 0
result = 0

while j < len(B):
    while i < len(A):
        if li < A[i]:
            l = i
            li = A[i]

        if A[i] == B[j]:
            break

        i += 1

    if i >= len(A):
        result = -1
        break

    AB[j + 1] = i
    AS[j + 1] = l
    l = i
    li = A[i]
    j += 1

for k in range(i, len(A)):
    if li < A[k]:
        l = k
        li = A[k]

AB[-1] = len(A)
AS[-1] = l

# print(A, B, AB, AS)

if X / K < Y:
    use_f = True
else:
    use_f = False


if result != -1:
    for i in range(1, len(B)+2):
        if AB[i] == AS[i] or AB[i-1] == AS[i] :
            if use_f:
                result += ((AB[i] - AB[i - 1] - 1) // K) * X + (AB[i] - AB[i - 1] - 1) % K * Y
            else:
                result += (AB[i] - AB[i - 1] - 1) * Y
        else:
            if 0 < AB[i] - AB[i - 1] - 1 < K:
                result = -1
                break
            else:
                if use_f:
                    result += ((AB[i] - AB[i - 1] - 1) // K) * X + (AB[i] - AB[i - 1] - 1) % K * Y
                else:
                    result += X + ((AB[i] - AB[i - 1] - 1) - K) * Y

print(result)
