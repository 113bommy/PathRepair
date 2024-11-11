mod = 1000000007
ii = lambda : int(input())
si = lambda : input()
dgl = lambda : list(map(int, input()))
f = lambda : map(int, input().split())
il = lambda : list(map(int, input().split()))
ls = lambda : list(input())
n=ii()
l=ls()
ch=['R','G','B']
c=0
for i in range(1,n-1):
    if l[i]==l[i-1]:
        c+=1
        for j in ch:
            if j!=l[i-1] and j!=l[i+1]:
                l[i]=j
if n>=2 and l[-1]==l[-2]:
    c+=1
    for j in ch:
        if j!=l[-2]:
            l[-1]=j
print(c)
print(''.join(l))
