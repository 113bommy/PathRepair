from sys import stdin


def main(a, b):
    print(a ^ b)


if __name__ == "__main__":
    t = int(stdin.readline())
    cases = [[int(s) for s in stdin.readline().split()] for _ in range(t)]
    for a, b in cases:
        main(a, b)
