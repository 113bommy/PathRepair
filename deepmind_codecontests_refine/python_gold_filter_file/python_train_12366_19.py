H, W, K = map(int, input().split())
S = [input() for _ in range(H)]

def count(n):
    A = [0]
    c = 0
    i = 1
    while(n):
        if n & 1:
            A.append(i)
            c += 1
        n >>= 1
        i += 1
    A.append(H)
    return c, A


ans = 2000
for n in range(1 << (H-1)):
    c, A = count(n)
    X = [0]*(len(A)-1)
    j = 0
    flag=True
    while j < W:
        for k in range(len(A)-1):
            for i in range(A[k], A[k+1]):
                if S[i][j] == "1":
                    X[k] += 1
        for x in X:
            if x > K:
                if flag:
                    c += 10000
                    break
                flag = True
                c += 1
                X = [0]*(len(A)-1)
                break
        else:
            flag = False
            j += 1
        if c > 10000:
            break
    ans = min(ans, c)
print(ans)
