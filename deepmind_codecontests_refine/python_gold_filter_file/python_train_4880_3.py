def dfs(i, b, c):
    if i == 11:
        return (b == sorted(b) and c == sorted(c))

    if dfs(i + 1, b + [balls[i - 1]], c):
        return True

    if dfs(i + 1, b, c + [balls[i - 1]]):
        return True

    return False


if __name__ == '__main__':
    N = int(input())
    for i in range(N):
        balls = list(map(int, input().split()))
        if dfs(1, [], []):
            print("YES")
        else:
            print("NO")