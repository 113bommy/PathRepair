A = input()
B = input()
n, m = len(A), len(B)
found = False
last = 0
ans = 0
for i in range(n-m+1):
    for j in range(m):
        if A[i+j] != B[j]: break
    else:
        if not found:
            last = i
            found = True
        elif last + m <= i:
            ans += 1
            last = i
print(ans+1 if found else ans)
