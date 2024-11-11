__author__ = 'MARI'


def main():
    a = int(input())
    print(1 + 12*(a*(a-1)//2))


if __name__ == '__main__':
    import sys

    argv = sys.argv
    main()
