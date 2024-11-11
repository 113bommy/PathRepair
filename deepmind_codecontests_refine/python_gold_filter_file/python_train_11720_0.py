# import io, os
# input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
import sys
# sys.stdin=open('input.txt','r')
# sys.stdout=open('output.txt','w')
input=sys.stdin.readline
# sys.setrecursionlimit(300010)
MOD = 1000000007
MOD2 = 998244353
ii = lambda: int(input().strip('\n'))
si = lambda: input().strip('\n')
dgl = lambda: list(map(int,input().strip('\n')))
f = lambda: map(int, input().strip('\n').split())
il = lambda: list(map(int, input().strip('\n').split()))
ls = lambda: list(input().strip('\n'))
lsi = lambda: [int(i) for i in ls()]
let = 'abcdefghijklmnopqrstuvwxyz'
for _ in range(1):
    n=ii()
    edges=[il() for i in range(n-1)]
    clr=[0]+il()
    deg=[0]*(n+1)
    tot=0
    for i in edges:
        if clr[i[0]]!=clr[i[1]]:
            deg[i[0]]+=1
            deg[i[1]]+=1
            tot+=1
    for i in range(1,n+1):
        if deg[i]==tot:
            exit(print('YES\n'+str(i)))
    print('NO')