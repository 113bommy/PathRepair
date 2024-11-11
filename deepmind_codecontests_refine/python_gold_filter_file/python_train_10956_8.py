from sys import stdin

for case in range(int(stdin.readline())):
    n,m = [int(x) for x in stdin.readline().split()]

    mid = 2**(m-1) - 1

    half = True

    used = []

    for a in range(n):
        used.append(int(stdin.readline(), 2))

    used.sort()

    passed = set()

    for a in used:
        passed.add(a)
        if a == mid:
            if half:
                half = False
                mid += 1
                while mid in passed:
                    mid += 1
            else:
                half = True
                mid -= 1
                while mid in passed:
                    mid -= 1
        elif a < mid:
            if half:
                mid += 1
                while mid in passed:
                    mid += 1
                half = False
            else:
                half = True
        else:
            if half:
                half = False
            else:
                half = True
                mid -= 1
                while mid in passed:
                    mid -= 1
    bruh = "{0:b}".format(mid)
    print('0'*(m-len(bruh))+bruh)

    
    

    
