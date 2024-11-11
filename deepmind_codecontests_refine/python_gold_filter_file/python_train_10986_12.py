# python3
import sys, threading, os.path
import string
import collections, heapq, math, bisect

sys.setrecursionlimit(10 ** 6)
threading.stack_size(2 ** 27)

def main():
    if os.path.exists('in.txt'):
        input = open('in.txt', 'r')
    else:
        input = sys.stdin
    # --------------------------------INPUT---------------------------------
    n = int(input.readline())
    lis = list(map(int, input.readline().split()))

    results = []
    for i, x in enumerate(lis):
        count = 1
        for j in range(i, -1, -1):
            if j == i:
                continue
            if j+1 >= len(lis) or lis[j] > lis[j+1]:
                break
            count += 1
        for j in range(i, len(lis), 1):
            if j == i:
                continue
            if lis[j] > lis[j-1]:
                break
            count += 1
        results.append(count)

    output = max(results)
    # -------------------------------OUTPUT----------------------------------
    if os.path.exists('out.txt'):
        open('out.txt', 'w').writelines(str(output))
    else:
        sys.stdout.write(str(output))


if __name__ == '__main__':
    main()
# threading.Thread(target=main).start()
