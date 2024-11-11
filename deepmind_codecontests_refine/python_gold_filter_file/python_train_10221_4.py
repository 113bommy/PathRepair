import sys
import math
fin = sys.stdin
a = [int (i) for i in fin.readline().rstrip('\n').split()]
s1,s2,questions = a[0],a[1],a[2]
gcd = math.gcd(s1,s2)
inter1 = s1//gcd
inter2 = s2//gcd
for i in range(questions):
    a = [int(i) for i in fin.readline().rstrip('\n').split()]
    if a[0] == 1:
        x = (a[1]-1)//inter1
    else:
        x = (a[1]-1)//inter2
    if a[2] == 1:
        y = (a[3]-1)//inter1
    else:
        y = (a[3]-1)//inter2
    if x == y:
        print('YES')
    else:
        print('NO')
