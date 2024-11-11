N,X,M = map(int,input().split())
ls = [X]
for i in range(M):
    Ai = ls[-1]**2 % M
    if Ai in ls:
        loop = ls[ls.index(Ai):]
        lenloop = len(loop)
        sumloop = sum(loop)
        startls = ls[:ls.index(Ai)]
        break
    ls.append(Ai)
if N <= len(startls):
    ans = sum(startls[:N])
else:
    ans = sum(startls) + ((N-len(startls))//lenloop)*sumloop + sum(loop[:(N-len(startls))%lenloop])
print(ans)
