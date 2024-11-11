import math


def main():
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    res = []
    for i in a:
        res.append(i)
    all_numbers = set([i for i in range(1, n+1)])
    seta = set(a)
    setb = set(b)
    non_a = list(all_numbers - seta)[0]
    non_b = list(all_numbers - setb)[0]
    dpa = double_positions(a)
    dpb = double_positions(b)
    for i in dpa:
        temp = res[i]
        res[i] = non_a
        if diff(res, a) == 1 and diff(res, b) == 1:
            print(*res)
            exit()
        res[i]= temp
    for i in dpb:
        temp = res[i]
        res[i] = non_b
        if diff(res, b) == 1 and diff(res, a) == 1:
            print(*res)
            exit()
        res[i] = temp



def diff(a, b):
    c = 0
    for i in range(len(a)):
        if a[i] != b[i]:
            c += 1
    return c

def double_positions(a):
    count = [-1 for i in range(len(a))]
    res = []
    for i in range(len(a)):
        if count[a[i]-1] != -1:
            return count[a[i]-1], i
        count[a[i]-1] = i
    
    
if __name__ == "__main__":
    main()
