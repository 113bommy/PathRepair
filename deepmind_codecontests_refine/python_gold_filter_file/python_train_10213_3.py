from collections import defaultdict
from string import ascii_lowercase
from sys import stdin, stdout
input = stdin.readline


def main():
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    mod = [defaultdict(int) for i in range(11)]  # number length 1-10, 1-indexed
    for val in a:
        mod[len(str(val))][val % k] += 1

    pairs = 0
    for val in a:
        for _len in range(1, 11):
            mod1 = (val * 10**_len) % k
            mod2 = k - mod1 if mod1 != 0 else 0
            pairs += mod[_len][mod2]
            if len(str(val)) == _len and val % k == mod2:
                pairs -= 1
    print(pairs)

if __name__ == '__main__':
    main()
