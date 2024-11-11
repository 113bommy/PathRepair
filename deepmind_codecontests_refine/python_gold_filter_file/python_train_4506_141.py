
if __name__ == '__main__':
    for _ in range(int(input())):
        a,b,c = map(int,input().split())
        m = max(a,b,c)
        k = min(a,b,c)
        r = a+b+c-m-k
        print(abs(m-k-r)+1)