from string import ascii_uppercase


def solve(n, k, s):
    c = {letter:0 for i, letter in enumerate(ascii_uppercase[:k])} 
    mini = 0
    for i in s:
        c[i] += 1
        mini = min(c.values())
    return k*mini


def main():
    n, k = list(map(int, input().split()))
    s = input()
    print(solve(n, k, s))


main()
