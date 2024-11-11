import statistics

def solve(n,m):
    med = 0
    if n== 1 and m==1:
        a = 1

    elif n % 2 == 0: ## if n is even number
        med = (n+1)/2

        if m > med:
            a = m-1
        elif m < med:
            a = m+1

    elif n % 2 != 0:
        med = n//2 + 1

        if m < med:
            a = m+1
        elif m > med:
            a = m-1
        else:
            a = m-1

    print(a)






if __name__ == '__main__':
    n,m = map(int, input().split())

    solve(n,m)