def main():
    k, q = map(int, input().split())
    d = list(map(int, input().split()))
    nxm = [list(map(int, input().split())) for _ in [0]*q]
    for n, x, m in nxm:
        d2 = sum([(i-1) % m+1 for i in d[:(n-2) % k+1]])
        d3 = sum([(i-1) % m+1 for i in d[(n-2) % k+1:]])
        print(n-1-(x % m+(d2+d3)*((n-2)//k)+d2)//m)


main()
