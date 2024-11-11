p = input().split()
t = ['C', 'C#', 'D', 'D#', 'E', 'F', 'F#', 'G', 'G#', 'A', 'B', 'H']
q = sorted([t.index(i) for i in p])
if q[2] - q[0] != 7: q = q[1: ] + [q[0] + 12]
if q[2] - q[0] != 7: q = q[1: ] + [q[0] + 12]
if q[1] - q[0] == 4 and q[2] - q[1] == 3: print('major')
elif q[1] - q[0] == 3 and q[2] - q[1] == 4: print('minor')
else: print('strange')