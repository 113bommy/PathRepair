A = input()
m = len(A)
B = "QAQ"*100
n = len(B)
F = [[0]*(n+1) for i in range(m+1)]
for i in range(1, m+1):
    for j in range(1, n+1):
        if A[i-1] == B[j-1]:
            F[i][j] = F[i-1][j-1] + 1
        else:
            F[i][j] = max(F[i-1][j], F[i][j-1])

ans = []
i = m
j = n
while i > 0 and j > 0:
    if A[i-1] == B[j-1]:
        ans.append(A[i-1])
        i -= 1
        j -= 1
    elif F[i][j] == F[i-1][j]:
        i = i - 1
    else:
        j = j - 1
ans = ans[::-1]
count = 0
for i in range(len(ans)-2):
    if ans[i] == "Q":
        for j in range(i+1, len(ans)-1):
            if ans[j] == "A":
                for k in range(j+1, len(ans)):
                    if ans[k] == "Q":
                        count += 1

print(count)