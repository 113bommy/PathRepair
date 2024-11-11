def main():
    n,m,k = [int(i) for i in input().split()]
    s = 'L' if k%2 == 1 else 'R'
    k = (k-1)//2
    d = k%m
    print(k//m+1, d+1, s)

if __name__ == "__main__":
    main()