n = int(input())
MAX = 1000000000

minimum, maximum, temp_max, temp_min = [0]*4

i = 0
while i < n:
    question = [x for x in input().split()]
    if question[2] == 'Y':
        if question[0] == ">=":
            minimum = int(question[1])
            maximum = MAX
        elif question[0] == ">":
            minimum = int(question[1])+1
            maximum = MAX
        elif question[0] == "<=":
            minimum = -MAX
            maximum = int(question[1])
        else:
            minimum = -MAX
            maximum = int(question[1])-1
    else:
        if question[0] == ">=":
            minimum = -MAX
            maximum = int(question[1]) - 1
        elif question[0] == ">":
            minimum = -MAX
            maximum = int(question[1])
        elif question[0] == "<=":
            minimum = int(question[1]) + 1
            maximum = MAX
        else:
            minimum = int(question[1])
            maximum = MAX
    if i == 0:
        temp_max = maximum
        temp_min = minimum
    else:
        temp_max = min(temp_max, maximum)
        temp_min = max(temp_min, minimum)
        if temp_max < temp_min and abs(temp_min) <= MAX and abs(temp_max) <= MAX:
            print("Impossible")
            exit()
    i += 1

if minimum != -MAX:
    print(temp_min)
else:
    print(temp_max)
