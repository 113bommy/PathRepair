a,b,c = list(map(int, input().strip().split()))

import sys

if a == 0:
    if b == 0:
        if c == 0:
            print(-1)
            sys.exit(0)
        else:
            print(0)
            sys.exit(0)
    else:
        print(1)
        print(-c/b)
        sys.exit(0)
else:
    a,b,c = 1, b/a, c/a

    if b == 0:
        if c == 0:
            print(1)
            print('{0:.10f}'.format(0))
            sys.exit(0)
        if c < 0:
            print(2)
            print('{0:.10f}'.format(-c**0.5))
            print('{0:.10f}'.format(c**0.5))
            sys.exit(0)
        if c > 0:
            print(0)
    else:
        if c == 0:
            nicli = set([0])
            nicli.add(-b)
            print(len(nicli))
            for e in sorted(list(nicli)):
                print('{0:.10f}'.format(e))
            sys.exit(0)
        else:
            d = b*b - 4*a*c
            if d < 0:
                print(0)
                sys.exit(0)
            elif abs(d) < 10**-12:
                print(1)
                print('{0:.10f}'.format(-b/(2*a)))
                sys.exit(0)
            else:
                x1 = max((-b + d**0.5) / (2*a),(-b - d**0.5) / (2*a))
                x2 = c/x1
                koreni = set()
                koreni.add(round(x1,10))
                koreni.add(round(x2,10))
                koreni = sorted(list(koreni))
                print(len(koreni))
                for e in koreni:
                    print('{0:.10f}'.format(e))
                sys.exit(0)
