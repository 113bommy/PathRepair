#-------------------------------------------------------------------------------
#http://codeforces.com/contest/1042/problem/A
#-------------------------------------------------------------------------------

def main():
    n = int(input())
    m = int(input())
    a = []
    for i in range(n):
        a.append(int(input()))
    M = max(a)
    MAX = M + m
    for i in range(n):
        while(a[i] < M):
            if m == 0:
                break
            a[i]+= 1
            m-=1
    average = m//n
    m = m%n
    if average:
        for i in range(n):
            a[i]+=average
    for i in range(n):
        if not m:
            break
        a[i]+=1
        m-=1
    MIN = max(a)
    print(MIN)
    print(MAX)

if __name__ == '__main__':
    main()
