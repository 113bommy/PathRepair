import math
def findlarg(n):
    i = 2
    while i*i <= n:
        if n%i == 0:
            return n//i
        i += 1
    return 1
q = int(input())
j = 0
a = []
while j < q:
    a.append(int(input()))
    j += 1
for i in range(q):
    if a[i] == 1:
        print (0)
    elif a[i] == 2:
        print (3)
    else:
        p = int(math.log2(a[i]))
        if (2**(p+1) - 1) == a[i]:
            print (findlarg(a[i]))
        else:
            print (2**(p+1) - 1)
            














