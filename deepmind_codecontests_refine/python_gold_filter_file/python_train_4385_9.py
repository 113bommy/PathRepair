Masha_Floor, Wants, elv_located, stair_passing, elv_passing, open_close = map(int, input().split())
"""Masha_Floor
Wants
elv_located
stair_passing
elv_passing
open_close"""
Difference = abs(Wants-Masha_Floor)
stair_time = Difference * stair_passing
elv_dfr = abs(Masha_Floor -elv_located)
difference_elv = abs(elv_located - Masha_Floor)
elv_time = (open_close*3)+(Difference*elv_passing)+(difference_elv*elv_passing)
if stair_time >= elv_time:
    print('YES')
else:
    print('NO')
#print(stair_time, elv_time)