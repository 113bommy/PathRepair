n = int(input())
A = [list(map(int,input().split())) for i in range(2)]
D = [[], []]

for i in range(3):
    if A[0][i] > A[1][i]:
        D[1].append([A[1][i], A[0][i]])
    else:
        D[0].append([A[0][i], A[1][i]])

def d1(x, in_0, out_0):
    return out_0 * (x // in_0) + (x % in_0)

def d2(x, in_0, out_0, in_1, out_1):
    ans = 0
    for i in range((x // in_0) + 1):
        ans = max(ans, out_0 * i + out_1 * ((x - i * in_0) // in_1) + ((x - i * in_0) % in_1))
    return ans

def d3(x, in_0, out_0, in_1, out_1, in_2, out_2):
    ans = 0
    for i in range((x // in_0) + 1):
        for j in range(((x - i * in_0) // in_1) + 1):
            ans = max(ans, out_0 * i + out_1 * j + out_2 * ((x - i * in_0 - j * in_1) // in_2) \
                + ((x - i * in_0 - j * in_1) % in_2))
            # print(i,j,ans)
    return ans

# print(D)

ans = 0
l = len(D[0])
if l == 3:
    ans = d3(n, D[0][0][0], D[0][0][1], D[0][1][0], D[0][1][1], D[0][2][0], D[0][2][1])
elif l == 2:
    ans = d1(d2(n, D[0][0][0], D[0][0][1], D[0][1][0], D[0][1][1]), D[1][0][0], D[1][0][1])
elif l == 1:
    ans = d2(d1(n, D[0][0][0], D[0][0][1]), D[1][0][0], D[1][0][1], D[1][1][0], D[1][1][1])
elif l == 0:
    ans = d3(n, D[1][0][0], D[1][0][1], D[1][1][0], D[1][1][1], D[1][2][0], D[1][2][1])

print(ans)