from collections import Counter
import sys

_ = input()
s = input()
c = Counter(s)

o, z = c['1'], c['0']

if o == 0:
    print(1)
    print(''.join('0' for _ in range(z)))
    sys.exit(0)

if z == 0:
    print(1)
    print(''.join('1' for _ in range(o)))
    sys.exit(0)

if o != z:
    # уже ок
    print(1)
    print(s)
else:
    print(2)
    print(s[0], s[1:])
