def toggle(val):
    if val == 1:
        return 0
    else:
        return 1

timed = [list(map(int, input().split())) for i in range(3)]

#intialize = [[0 for i in range(3)] for i in range(3)]

curr_state = [[1 for i in range(3)] for i in range(3)]

temp = 0

for i in range(3):
    for j in range(3):
        if timed[i][j] > temp:
            temp = timed[i][j]


for i in range(timed[0][0]):
    curr_state[0][0] = toggle(curr_state[0][0])
    curr_state[0][1] = toggle(curr_state[0][1])
    curr_state[1][0] = toggle(curr_state[1][0])
    #curr_state[1][1] = toggle(curr_state[1][1])

for _ in range(timed[0][1]):
    curr_state[0][1] = toggle(curr_state[0][1])
    curr_state[0][0] = toggle(curr_state[0][0])
    curr_state[0][2] = toggle(curr_state[0][2])
    curr_state[1][1] = toggle(curr_state[1][1])
    #curr_state[1][0] = toggle(curr_state[1][0])
    #curr_state[1][2] = toggle(curr_state[1][2]) 

for _ in range(timed[0][2]):
    curr_state[0][2] = toggle(curr_state[0][2])
    curr_state[0][1] = toggle(curr_state[0][1])
    curr_state[1][2] = toggle(curr_state[1][2])
    #curr_state[1][1] = toggle(curr_state[1][1])

for _ in range(timed[1][0]):
    curr_state[1][0] = toggle(curr_state[1][0])
    curr_state[0][0] = toggle(curr_state[0][0])
    curr_state[2][0] = toggle(curr_state[2][0])
    curr_state[1][1] = toggle(curr_state[1][1])
    #curr_state[0][1] = toggle(curr_state[0][1])
    #curr_state[2][1] = toggle(curr_state[2][1])    

for _ in range(timed[1][1]):
    curr_state[1][1] = toggle(curr_state[1][1])
    curr_state[0][1] = toggle(curr_state[0][1])
    curr_state[1][0] = toggle(curr_state[1][0])
    curr_state[1][2] = toggle(curr_state[1][2])
    curr_state[2][1] = toggle(curr_state[2][1])
    #curr_state[0][0] = toggle(curr_state[0][0])
    #curr_state[0][2] = toggle(curr_state[0][2])
    #curr_state[2][0] = toggle(curr_state[2][0])
    #curr_state[2][2] = toggle(curr_state[2][2])    

for _ in range(timed[1][2]):
    curr_state[1][2] = toggle(curr_state[1][2])
    curr_state[0][2] = toggle(curr_state[0][2])
    curr_state[1][1] = toggle(curr_state[1][1])
    curr_state[2][2] = toggle(curr_state[2][2])
    #curr_state[0][1] = toggle(curr_state[0][1])
    #curr_state[2][1] = toggle(curr_state[2][1])

for _ in range(timed[2][0]):
    curr_state[2][0] = toggle(curr_state[2][0])
    curr_state[1][0] = toggle(curr_state[1][0])
    curr_state[2][1] = toggle(curr_state[2][1])
    #curr_state[1][1] = toggle(curr_state[1][1])

for _ in range(timed[2][1]):
    curr_state[2][1] = toggle(curr_state[2][1])
    curr_state[1][1] = toggle(curr_state[1][1])
    curr_state[2][0] = toggle(curr_state[2][0])
    curr_state[2][2] = toggle(curr_state[2][2])
    #curr_state[1][0] = toggle(curr_state[1][0])
    #curr_state[1][2] = toggle(curr_state[1][2])

for _ in range(timed[2][2]):
    curr_state[2][2] = toggle(curr_state[2][2])
    curr_state[1][2] = toggle(curr_state[1][2])
    curr_state[2][1] = toggle(curr_state[2][1])
    #curr_state[1][1] = toggle(curr_state[1][1])
'''
if (timed[0][0] >= temp and timed[0][0] > 0):
    #print(curr_state[0][1], curr_state[1][0])
    #curr_state[0][0] = toggle(curr_state[0][0])
    #curr_state[0][1] = toggle(curr_state[0][1])
    #curr_state[1][0] = toggle(curr_state[1][0])
    #curr_state[1][1] = toggle(curr_state[1][1])
    sum1 = timed[0][0] + timed[0][1] + timed[1][0] + timed[1][1]
    if sum1 & 1:
        curr_state[0][0] = 1
    else:
        curr_state[0][0] = 0
    #print(curr_state[0][1], curr_state[1][0])
if (timed[0][1] >= temp and timed[0][1] > 0):
    #print("fck")
    #curr_state[0][1] = toggle(curr_state[0][1])
    #curr_state[0][0] = toggle(curr_state[0][0])
    #curr_state[0][2] = toggle(curr_state[0][2])
    #curr_state[1][1] = toggle(curr_state[1][1])
    #curr_state[1][0] = toggle(curr_state[1][0])
    #curr_state[1][2] = toggle(curr_state[1][2])
    sum1 = timed[0][1] + timed[0][0] + timed[0][2] + timed[1][1] + timed[1][0] + timed[1][2]
    if sum1 & 1:
        curr_state[0][1] = 1
    else:
        curr_state[0][1] = 0
if (timed[0][2] >= temp and timed[0][2] > 0):
    #curr_state[0][2] = toggle(curr_state[0][2])
    #curr_state[0][1] = toggle(curr_state[0][1])
    #curr_state[1][2] = toggle(curr_state[1][2])
    #curr_state[1][1] = toggle(curr_state[1][1])
    sum1 = timed[0][2] + timed[0][1] + timed[1][2] + timed[1][1]
    if sum1 & 1:
        curr_state[0][2] = 1
    else:
        curr_state[0][2] = 0
if (timed[1][0] >= temp and timed[1][0] > 0):
    #curr_state[1][0] = toggle(curr_state[1][0])
    #curr_state[0][0] = toggle(curr_state[0][0])
    #curr_state[2][0] = toggle(curr_state[2][0])
    #curr_state[1][1] = toggle(curr_state[1][1])
    #curr_state[0][1] = toggle(curr_state[0][1])
    #curr_state[2][1] = toggle(curr_state[2][1])
    sum1 = timed[1][0] + timed[0][0] + timed[2][0] + timed[1][1] + timed[0][1] + timed[2][1]
    if sum1 & 1:
        curr_state[1][0] = 1
    else:
        curr_state[1][0] = 0
if (timed[1][1] >= temp and timed[1][1] > 0):
    #curr_state[1][1] = toggle(curr_state[1][1])
    #curr_state[0][1] = toggle(curr_state[0][1])
    #curr_state[1][0] = toggle(curr_state[1][0])
    #curr_state[1][2] = toggle(curr_state[1][2])
    #curr_state[2][1] = toggle(curr_state[2][1])
    #curr_state[0][0] = toggle(curr_state[0][0])
    #curr_state[0][2] = toggle(curr_state[0][2])
    #curr_state[2][0] = toggle(curr_state[2][0])
    #curr_state[2][2] = toggle(curr_state[2][2])
    sum1 = timed[0][0] + timed[0][1] + timed[0][2] + timed[1][0] + timed[1][1] + timed[1][2] + timed[2][0] + timed[2][1] + timed[2][2]
    if sum1 & 1:
        curr_state[1][1] = 1
    else:
        curr_state[1][1] = 0
if (timed[1][2] >= temp and timed[1][2] > 0):
    #curr_state[1][2] = toggle(curr_state[1][2])
    #curr_state[0][2] = toggle(curr_state[0][2])
    #curr_state[1][1] = toggle(curr_state[1][1])
    #curr_state[2][2] = toggle(curr_state[2][2])
    #curr_state[0][1] = toggle(curr_state[0][1])
    #curr_state[2][1] = toggle(curr_state[2][1])
    sum1 = timed[1][2] + timed[0][2] + timed[1][1] + timed[2][2] + timed[0][1] + timed[2][1]
    if sum1 & 1:
        curr_state[1][2] = 1
    else:
        curr_state[1][2] = 0
if (timed[2][0] >= temp and timed[2][0] > 0):
    #curr_state[2][0] = toggle(curr_state[2][0])
    #curr_state[1][0] = toggle(curr_state[1][0])
    #curr_state[2][1] = toggle(curr_state[2][1])
    #curr_state[1][1] = toggle(curr_state[1][1])
    sum1 = timed[2][0] + timed[1][0] + timed[2][1] + timed[1][1]
    if sum1 & 1:
        curr_state[2][0] = 1
    else:
        curr_state[2][0] = 0
if (timed[2][1] >= temp and timed[2][1] > 0):
    #curr_state[2][1] = toggle(curr_state[2][1])
    #curr_state[1][1] = toggle(curr_state[1][1])
    #curr_state[2][0] = toggle(curr_state[2][0])
    #curr_state[2][2] = toggle(curr_state[2][2])
    #curr_state[1][0] = toggle(curr_state[1][0])
    #curr_state[1][2] = toggle(curr_state[1][2])
    sum1 = timed[2][1] + timed[1][1] + timed[2][0] + timed[2][2] + timed[1][0] + timed[1][2]
    if sum1 & 1:
        curr_state[2][1] = 1
    else:
        curr_state[2][1] = 0
if (timed[2][2] >= temp and timed[2][2] > 0):
    #curr_state[2][2] = toggle(curr_state[2][2])
    #curr_state[1][2] = toggle(curr_state[1][2])
    #curr_state[2][1] = toggle(curr_state[2][1])
    #curr_state[1][1] = toggle(curr_state[1][1])
    sum1 = timed[2][2] + timed[1][2] + timed[2][1] + timed[1][1]
    if sum1 & 1:
        curr_state[2][2] = 1
    else:
        curr_state[2][2] = 0
'''
for i in range(3):
    for j in range(3):
        print(curr_state[i][j], end='')
    print()