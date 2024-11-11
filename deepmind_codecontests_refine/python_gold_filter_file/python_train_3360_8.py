t = int(input())

ns = []
xs = []

arrs = []

for _ in range(t):
    enter = input().split(" ")
    enter = [int(x) for x in enter]
    ns.append(enter[0])
    xs.append(enter[1])

    arrs.append([ int(x) for x in input().split(" ")])

for i in range(t):
    n = ns[i]
    x = xs[i]
    arr = arrs[i]
    all_equal = True
    difference = 0
    is_in = False

    
    for a in arr:
        if x-a != 0:
            all_equal = False
        else:
            is_in = True
        difference += x-a
        
    if all_equal == True:
        print (0)
    elif difference == 0 or is_in == True:
        print (1)
    else:
        print(2)

