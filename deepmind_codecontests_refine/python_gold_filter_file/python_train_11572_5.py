# import time

def index(s):
    result = [[] for i in range(27)]
    for i in range(len(s)):
        if s[i] == '?':
            result[-1].append(i + 1)
        else:
            result[ord(s[i]) - ord('a')].append(i + 1)
    return result

def solve(s1, s2):
    i1, i2 = index(s1), index(s2)
    result = []
    for a, b in zip(i1[:26], i2[:26]):
        while a and b:
            result.append((a.pop(), b.pop()))

    for l in i2:
        if not i1[-1]:
            break
        while i1[-1] and l:
            result.append((i1[-1].pop(), l.pop()))
    for l in i1:
        if not i2[-1]:
            break
        while i2[-1] and l:
            result.append((l.pop(), i2[-1].pop()))
    while i1[-1] and i2[-1]:
        result.append(i1[-1].pop(), i2[-1].pop())
    return result

def main():
    n = int(input())
    s1 = input()
    s2 = input()
    # tick = time.time()
    result = solve(s1, s2)
    print(len(result))
    for a, b in result:
        print(a, b)
    # tock = time.time()
    # print('T:', round(tock - tick, 5))

if __name__ == "__main__":
    main()