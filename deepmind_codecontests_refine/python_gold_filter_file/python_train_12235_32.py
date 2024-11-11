import sys,math

inputs = iter(sys.stdin.readlines())
n = int(next(inputs))
print(int(2*4*3*pow(4,n-3) + (n-3)*4*3**2*pow(4,n-4)))
