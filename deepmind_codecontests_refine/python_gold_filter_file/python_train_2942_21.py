import math
t = int(input())
cases = []
for i in range(t):
    cases.append(int(input()))
 
def solve(case):
    print(math.ceil(case/2))
 
for case in cases:
    solve(case)
 
