if __name__ == '__main__':
    n = int(input())
    print(' '.join([str((it - 1) % n + 1) for it in range(n)]))
