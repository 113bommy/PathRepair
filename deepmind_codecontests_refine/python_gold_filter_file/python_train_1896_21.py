import math, time

start_time = time.time()
def check_stacks(num):
    add=0
    if num%14>6:
        add=1
    return math.floor(num/14)+add

#algorithm
def dice_algorithm(desire):
    if desire in range(1, 15):
        print('NO')
    elif desire%14 in range(1, 7):
        print('YES')
    else:
        print('NO')

#inputs
sets = input()
fav_ints = [x for x in input().split()]

for y in fav_ints:
    dice_algorithm(int(y))