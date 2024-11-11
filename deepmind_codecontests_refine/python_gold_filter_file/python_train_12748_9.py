import sys

def main():
    n = int(sys.stdin.read().strip())
    c, j = 1, 1
    out = []
    for i in range(n-1):
        out.append((j+c)%n or n)
        j += c
        c += 1
    return out
    
print(*main())

