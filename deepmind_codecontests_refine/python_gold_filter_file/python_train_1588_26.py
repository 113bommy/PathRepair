from math import pi, sin, tan

def solution():
    # n, k = map(int, input().split())
    # n = int(intput())
    n = int(input())*2


    return 1/(tan(pi/n))
    
for _ in range(int(input())):
    print(solution())