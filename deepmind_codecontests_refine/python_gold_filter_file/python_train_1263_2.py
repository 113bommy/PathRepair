from collections import Counter

if __name__ == "__main__":
    b, k = tuple(map(int, input().split(' ')))

    a = tuple(map(int, input().split(' ')))
    if b % 2 == 0:
        print('odd' if a[-1] % 2 else 'even')
    else:
        odds = 0
        for i in a:
            odds += 1 if i % 2 == 1 else 0
        print('odd' if odds % 2 else 'even')
