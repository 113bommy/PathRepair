def solve():
    _ = input()
    c = len(list(filter(lambda i: i % 2 == 1, map(int, input().rstrip().split()))))
    if c >= 1:
        print('First')
    else:
        print('Second')

solve()
