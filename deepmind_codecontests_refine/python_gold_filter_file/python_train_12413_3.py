import collections
def calc(A):
    cnt = collections.Counter(A)
    max_ = max(cnt.values())
    len_ = len(cnt)
    res = min(len_ - 1, max_)
    if res + 1 <= len(A) // 2 and max_ > res + 1:
        res += 1 
    return res

if __name__ == '__main__':
    N = int(input())
    cases = []
    for _ in range(N):
        _ = input()
        cases.append(list(map(int, input().split())))
    for case in cases:
        print(calc(case))