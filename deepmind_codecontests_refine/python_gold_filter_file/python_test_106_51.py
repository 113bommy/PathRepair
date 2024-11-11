def solve(n):
    return [i for i in range(2, n+2)]

if __name__ == '__main__':
    ans = []
    for _ in range(int(input())):
        ans.append(solve(int(input())))
    for a in ans:
        print(*a)




