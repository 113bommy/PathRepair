target = tuple(map(int, input().split()))
s = input()

#print(target)
#print(s)

ok = False
pos = (0, 0)
for c in s:
    if c == 'L': pos = (pos[0]-1, pos[1])
    if c == 'R': pos = (pos[0]+1, pos[1])
    if c == 'U': pos = (pos[0], pos[1]+1)
    if c == 'D': pos = (pos[0], pos[1]-1)
    if pos == target: ok = True

if pos == (0, 0):           #termin pe pozitia din care am pornit
    if ok: print('Yes')
    else: print('No')
    exit()

if pos[0] == 0:
    if target[1] * pos[1] < 0: raport = 0
    else: raport = target[1] // pos[1]
else:
    if target[0] * pos[0] < 0: raport = 0
    else: raport = target[0] // pos[0]

if raport > 0: raport = max(0, raport - 1000)
if raport < 0: raport = min(0, raport + 1000)

#print('Ajung in (%i, %i) dupa o executie, si raport = %i' %(pos[0], pos[1], raport))

coord = (pos[0] * raport, pos[1]*raport)
for rep in range(0, 5000):
    if coord == target: ok = True
    for c in s:
        if c == 'L': coord = (coord[0]-1, coord[1])
        if c == 'R': coord = (coord[0]+1, coord[1])
        if c == 'U': coord = (coord[0], coord[1]+1)
        if c == 'D': coord = (coord[0], coord[1]-1)
        if coord == target: ok = True
    
if ok: print('Yes')
else: print('No')
