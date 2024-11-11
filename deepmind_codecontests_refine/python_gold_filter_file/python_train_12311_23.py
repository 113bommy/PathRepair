import sys

input = sys.stdin.readline

############ ---- Input Functions ---- ############
def inp():
    return (int(input()))
def instr():
    return (str(input()))
def inlt():
    return (list(map(int, input().split())))
# def insr():
#     s = input()
#     return(list(map(int, list(s[:len(s) - 1]))))
def insr():
    s = input()
    return list(s[:len(s) - 1])
def invr():
    return (map(int, input().split()))


from collections import Counter


def main():
    t = inp()
    for _ in range(t):
        a, b, c = inlt()
        if c <= a:
            print(-1, b)
        elif a * b <= c:
            print(1, -1)
        else:
            print(1, b)
    



if __name__ == '__main__':
    main()
