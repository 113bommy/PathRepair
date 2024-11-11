N = int(input())
S = input()
temp = S.count('.')
cnt = min(temp, N)

for i in range(N):
    if S[i] == '#':
        temp += 1
    else:
        temp -= 1
    cnt = min(temp, cnt)
print(cnt)