def solution(s) -> None:
    print(1)


def main():
    t = int(input())
    j = 1
    cur = 0
    row = 0
    s = [[] for i in range(t)]
    while j < t*t + 1:
        if cur == 0:
            for i in range(t):
                s[row + i].append(j + i)
        else:
            for i in range(t):
                s[row + i].append(j + t - i - 1)
        j = j + t
        cur = 1 - cur
    print("\n".join(map(lambda x: " ".join(map(str, x)), s)))



if __name__ == "__main__":
    main()
