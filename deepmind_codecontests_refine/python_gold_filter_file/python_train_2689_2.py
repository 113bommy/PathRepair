import random


def mid_1(X):
    return X[(len(X)) // 2]


def mid(X):
    return X[(len(X)) // 2 - 1]


def main():
    N = int(input())

    X = list(map(int, input().split()))
    # N = 200000
    # X = [random.randint(0, 1000000000) for _ in range(N)]
    X_ = X[:]
    X_.sort()
    X__ = X_[:N // 2]
    X__ = X__[-1]

    x_1 = mid_1(X_)
    x = mid(X_)

    ans = []
    # print(X_)
    # print(X__)
    for i in range(N):
        if X[i] <= X__:
            print(x_1)
            # ans.append(x_1)
        else:
            print(x)
            # ans.append(x)


if __name__ == '__main__':
    main()