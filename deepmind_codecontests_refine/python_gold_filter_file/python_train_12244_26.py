kn = input().split()
color = input()
cd = dict()
for c in color:
    cd[c]=cd.get(c,0)+1
lst = list()
for key, value in cd.items():
    lst.append((value, key))
lst.sort(reverse=True)
for key, value in lst[:1]:
    print('YES' if key<=int(kn[1]) else 'NO')
