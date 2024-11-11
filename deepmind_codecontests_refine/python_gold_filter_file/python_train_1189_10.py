

def main():
    n,m = map(int,input().split())
    s = ""
    if 2*n+2 < m:
        print(-1)
        return
    if n > m:
        if n-1 > m:
            print(-1)
            return
        else:
            s = "0"
    while m > n+1 and n > 0:
        s += "110"
        n -= 1
        m -= 2
    while m > 0 and n > 0:
        s += "10"
        n -= 1
        m -= 1
    s += "1"*m
    print(s)
main()
    