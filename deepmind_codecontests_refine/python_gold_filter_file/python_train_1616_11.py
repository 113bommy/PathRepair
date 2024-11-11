import sys

for line in sys.stdin:
    a = sys.stdin.readline().split()
    out = '1'
    for n in a:
        v = 1
        c1 = 0
        for c in n:
            if(c == '1'):
                c1 += 1
                if(c1 > 1):
                    v = 2
                    break
            elif(c == '0'):
                if(c1 == 0):
                    v = 0
                    break
            else:
                v = 2
                break
        if(v == 1):
            out += n[1:]
        elif(v == 0):
            out = '0'
            break
        else:
            out = n + out[1:]
    print(out)
