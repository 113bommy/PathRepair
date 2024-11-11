from collections import defaultdict
left,right=defaultdict(list),defaultdict(list)
indexs=[]
n=int(input())
l=input()
r=input()
for i in range(n):
    left[l[i]].append(i)
    right[r[i]].append(i)
l=set(map(str,l))
r=set(map(str,r))
common=l.union(r)
if '?' in common:
    common.remove('?')
pairs=[]
for i in common:
    while left[i] and right[i]:
        pairs.append([left[i].pop()+1,right[i].pop()+1])
    while left[i]and right['?']:
        pairs.append([left[i].pop()+1,right['?'].pop()+1])
    while left['?'] and right[i]:
        pairs.append([left['?'].pop()+1,right[i].pop()+1])
while left['?'] and right['?']:
        pairs.append([left['?'].pop()+1,right['?'].pop()+1])
print(len(pairs))
for i in pairs:
    print(*i)