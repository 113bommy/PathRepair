def solve_testcase(n : int, permutation : list):
    begin = 0
    end = n - 1
    flag = False
    for i in range(n, 0, -1):
        if permutation[begin] == i:
            begin += 1
        elif permutation[end] == i:
            end -= 1
        else: # found the middle element
            idx = permutation.index(i)
            flag = True
            break
    if flag:
        for i in range(begin, idx + 1):
            if permutation[i] < permutation[idx]:
                a = i
                break
        for i in range(idx, end + 1):
            if permutation[i] < permutation[idx]:
                b = i
                break
        print("YES")
        print(a + 1, idx + 1, b + 1)
    else:
        print("NO")

def input_testcase():
    n = int(input())
    perm = [int(term) for term in input().split()]
    return n, perm

t = int(input())
for i in range(t):
    solve_testcase(*input_testcase())