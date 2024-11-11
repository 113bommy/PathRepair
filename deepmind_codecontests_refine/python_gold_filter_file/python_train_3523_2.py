H, W = map(int, input().split())
N = int(input())
a = list(map(int, input().split()))
ans_lis = []

for i in range(N):
    ans_lis = ans_lis + [i + 1] * a[i]

for i in range(H):

    if i % 2 == 0:
        k = 1
    else:
        k = -1

    ans = ans_lis[i * W:(i + 1) * W][::k]
    ans = list(map(str, ans))
    print(" ".join(ans))
