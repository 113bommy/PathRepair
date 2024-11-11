import sys
stdin = sys.stdin

sys.setrecursionlimit(10**5)

def li(): return map(int, stdin.readline().split())
def li_(): return map(lambda x: int(x)-1, stdin.readline().split())
def lf(): return map(float, stdin.readline().split())
def ls(): return stdin.readline().split()
def ns(): return stdin.readline().rstrip()
def lc(): return list(ns())
def ni(): return int(stdin.readline())
def nf(): return float(stdin.readline())

def light_length(a:int, b:int) -> int:
    if a > b:
        a,b = b,a
    
    if b%a == 0:
        return 2 * a * (b//a) - a

    return 2 * (b//a) * a + light_length(a, b%a)

n,x = li()

print(n + light_length(x,n-x))  