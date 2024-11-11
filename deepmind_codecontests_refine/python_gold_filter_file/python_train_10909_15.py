N = int(input())
S = input()

cnt = 0
for i in range(1000):
    key = str(i).zfill(3)
    ki = 0
    for j in range(N):
        if key[ki] == S[j]: ki += 1
        if ki == 3:
            cnt += 1
            break

print(cnt)
