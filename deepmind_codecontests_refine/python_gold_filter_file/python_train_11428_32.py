N,X,M = map(int,input().split(" "))
q = [-1] * (M + 1)
A = X
i = 0
su = []
p1 = 0
p2 = 0
while q[A] == -1:
    q[A] = i
    su.append(A)
    A = (A * A) % M
    i += 1

if N == len(su):
    print(sum(su))
else:
    r = q[A]
    r2 = (N - r) % (i - r)

    ans1 = sum(su[0:r])
    ans2 = sum(su[r:r + r2])
    ans3 = sum(su[r::])

    print(ans1 + ans2 + ans3 * ((N - r) // (i - r)))