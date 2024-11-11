# B
N, K = map(int, input().split())
a_list = list(map(int, input().split()))
NN = N*(N+1) // 2

arr = [0] * NN
res = 0

# bruce
ind = 0
for i in range(N):
    r = 0
    for j in range(i, N):
        r += a_list[j]
        arr[ind] = r
        ind += 1
        
# get Greedy
for m in range(40, -1, -1):
    cnt = 0
    for i in range(NN):
        if (arr[i] // (2**m)) % 2 == 1:
            cnt += 1
    if cnt >= K:
        res += 2**m
        for i in range(NN):
            if (arr[i] // (2**m)) % 2 == 0:
                arr[i] = 0

print(res)