N = int(input())
S = input()
ans = 0
for i in range(1000):
    i = str(i).zfill(3)
    c = 0
    for j in range(N):
        if S[j] == i[c]:
            c += 1
        
        if c == 3:
            ans += 1
            break

print(ans)