t = int(input())
for i in range(t):
    n = int(input())
    total = ''
    for j in range(n):
        s = input().strip()
        total += s
    total = sorted(total)
    boolean = True
    first = 0
    for k in range(1, len(total)):
        if total[k] != total[k-1]:
            if (k-first)%n != 0:
                print('no')
                boolean = False
                break
            else:
                first = k
        if k == len(total)-1:
            if (k+1-first)%n != 0:
                print('no')
                boolean = False
    if boolean:
        print('yes')
