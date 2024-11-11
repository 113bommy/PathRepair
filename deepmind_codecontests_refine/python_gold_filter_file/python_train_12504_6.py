n, k = map(int, input().split())
A = list(map(int, input().split()))
min_ = min(A)
A = [A[i] - min_ for i in range(n)]
A.sort(reverse=True)
was = max(A)
i = 0
sum_ = 0
c = 0
ans = 0
last = was
while was >= 0:
    sumt = 0
    c1 = 0
    while i < len(A) and A[i] >= was:
        sumt += A[i] - was
        c1 += 1
        i += 1
    if sumt + sum_ + c + c1 > k:
        ans += 1
        sum_ = c + c1
        c += c1
        last = was
    else:
        sum_ += sumt + c + c1
        c += c1
    was -= 1
if last > 0:
    ans += 1
print(ans)