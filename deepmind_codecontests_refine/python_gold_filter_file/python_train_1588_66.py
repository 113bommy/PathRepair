from sys import stdin, stdout
from math import sin, pi, tan
"""
    n = stdin.readline()
    arr = [int(x) for x in stdin.readline().split()]
    stdout.write(str(summation))
"""
for test in range(int(stdin.readline())) :
    n = int(stdin.readline())
    #x = (((2*n)-2)*180)/(2*n)
    #ans = 1+((n-2)*(sin(((pi)/180)*x)))
    ans = 1/tan(pi/(2*n))
    #print(x, sin(((pi)/180)*x), ((n-2)*(sin(((pi)/180)*x))))
    stdout.write(str(ans)+"\n")