pan = input().split('|')
free = input()
left = pan[0]
right = pan[1]


possible = False 

if len(left) == len(right):
    if (len(free) % 2 == 0):
        possible = True
else:
    diff = max(len(left) - len(right), len(right)- len(left))
    if len(free) >= diff  and (len(free) - diff) % 2 == 0:
        possible = True
        

if possible:
    total = len(left) + len(right) + len(free)
    i = 0
    while (len(left) < total / 2):
        left+= free[i]
        i+=1
    for j in range(i, len(free)):
        right+=free[j]
    print(left+'|'+right)
else:
    print('Impossible')