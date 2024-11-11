
import sys
def get_single_int ():
    return int (sys.stdin.readline ().strip ())
def get_string ():
    return sys.stdin.readline ().strip ()
def get_ints ():
    return map (int, sys.stdin.readline ().strip ().split ())
def get_list ():
    return list (map (int, sys.stdin.readline ().strip ().split ()))

#code starts here
n, a, b = get_ints ()
if (a*b) < n:
    print (-1);
else:
    ans = []
    for i in range (b):
        tmp = []
        for j in range (a):
            calculation = (i)*a + j + 1
            if calculation > n:
                tmp.append (0)
            else:
                tmp. append (calculation)
        if i % 2 == 0:
            ans.append (tmp)
        else:
            ans. append (list (reversed (tmp)))
    for k in range (a):
        for m in range (b):
            if m == b - 1:
                print (ans [m] [k], end = '\n')
            else:
                print (ans [m] [k], end = ' ')

