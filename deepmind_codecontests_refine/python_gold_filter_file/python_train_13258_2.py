def solve(s, n, bag):
    bag.sort(key=lambda x: x[0])
    for item in bag:
        if item[0] >= s:
            return 'NO'
        s += item[1]
    return "YES"


def main():
    s, n = list(map(int, input().split()))    
    bag = [tuple(map(int, input().split())) for _ in range(n)]
    print(solve(s, n, bag))


main()
