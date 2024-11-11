#>=はmの倍数をまたいだ回数
k,q = map(int, input().split( ))
d = list(map(int, input().split( )))
from collections import Counter
for i in range(q):
    n,x,m=map(int, input().split( ))
    dx = [di%m for di in d]
    ##あまり0をあまりmで処理
    for i in range(k):
        if dx[i]==0:
            dx[i]=m
    sm = x%m+sum(dx)*((n-1)//k)+sum(dx[:(n-1)%k])
    print(n-1 -sm//m)
