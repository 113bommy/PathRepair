N = int(input())
S = input()
k = 1
for i in range(N - 1):
    while True:
        if S[i : i + k] in S[i + k :]:
            k += 1
        else:
            break
print(k - 1)