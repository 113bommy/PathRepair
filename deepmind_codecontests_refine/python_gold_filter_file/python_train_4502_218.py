import math

def n_even(n):
    return (n/2)-1
def n_odd(n):
    return math.floor(n/2)

t = int(input())

for i in range(t):
    n = int(input())

    if n <= 2:
        print(0)
    elif n%2 == 0:
        print(int(n_even(n)))
    else:
        print(int(n_odd(n)))