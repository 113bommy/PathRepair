

def solve():
    n = int(input())
    for i in range(n):
        x = int(input())-1
        if x > 1:
            print(x//2)
        else:
            print(0)


if __name__ == "__main__":
    solve()