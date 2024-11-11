if __name__ == '__main__':
    n = int(input())
    for x in range(n):
        startx, starty, diffx, diffy = map(int, input().split())
        result = (starty - startx) / (diffx + diffy)
        if result == round(result):
            print(round(result))
        else:
            print(-1)