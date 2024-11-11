import sys
M = 10**9 + 7

def fmodM(n):
    if n >= M:
        return 0
    result = 1
    for i in range(2, n+1):
        result = (result * i) % M
    return result

def answer(n):
    
    total = fmodM(n)
    acyclic = 2**(n-1) % M
    return (total - acyclic) % M

def main():
    n = int(sys.stdin.readline())
    print(answer(n))
    return
main()