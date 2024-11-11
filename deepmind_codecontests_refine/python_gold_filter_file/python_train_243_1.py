from sys import stdin
from collections import defaultdict
input = stdin.readline

def put():
    return map(int, input().split())

def find(i):
    if i==p[i]:
        return i
    p[i]=find(p[i])
    return p[i]

def union(i,j):
    if rank[i]>rank[j]:
        i,j = j,i
    elif rank[i]==rank[j]:
        rank[j]+=1
    p[i]=j

n = int(input())
graph = [[] for i in range(n)]
extra,p,rank = [], list(range(n)), [0]*n
for _ in range(n-1):
    x,y = put()
    i,j = map(find, (x-1, y-1))
    if i!=j:
        union(i,j)
    else:
        extra.append((x,y))

s = set(map(find, range(n)))
#print(s)
x = s.pop()
print(len(s))
for y in s:
    u,v = extra.pop()
    print(u,v,x+1,y+1)
