import sys

if __name__ == '__main__':
    n = list(map(int, sys.stdin.readline().split(" ")))[0]
    a = list(sys.stdin.readline())
    x = list(map(int, sys.stdin.readline().split(" ")))
    m = 100000000000
    for i in range(n-1):
        if a[i]=='R' and a[i+1]=='L':
            m = min(m,(x[i+1]-x[i])/2)
    if m == 100000000000 :
        m = -1
    print(int(m))
