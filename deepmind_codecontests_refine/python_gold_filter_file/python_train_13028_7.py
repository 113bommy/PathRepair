n = int(input())
s = list(map(int,input().split()))[:n]
d = []
if 2 in s:
    s.remove(2)
    d.append(2)
if 1 in s:
    s.remove(1)
    d.append(1)
for i in range(s.count(2)):
    d.append(2)
if 1 in s:     
    for i in range(s.count(1)):
        d.append(1)
print(*d)        
