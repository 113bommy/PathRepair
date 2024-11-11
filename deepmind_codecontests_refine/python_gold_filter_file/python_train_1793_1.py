import sys

input = sys.stdin.buffer.readline

def find_pair(candidate,data,m):
    ans = (-1,-1)
    binary_bit = [False for i in range(1 << m)]
    for i in data:
        bit_tmp = 0
        for j in range(len(i)):
            if i[j] >= candidate: bit_tmp |= 1 << j
        binary_bit[bit_tmp] = True
    
    for i in range(1 << m):
        for j in range(1 << m):
            if i | j == (( 1 << m ) - 1) and binary_bit[i] and binary_bit[j]:
                ans = i , j
                break
    return ans

def backtracking(candidate,ans,data):
    idx_i = -1 ; idx_j = -1
    for i in range(len(data)):
        bit_tmp = 0
        for j in range(len(data[i])):
            if data[i][j] >= candidate: bit_tmp |= 1 << j
        if bit_tmp == ans[0]: idx_i = i
        if bit_tmp == ans[1]: idx_j = i

    print(str(idx_i + 1) + " " + str(idx_j + 1))

def main():
    n , m = [int(i) for i in input().split()]
    data = [[int(i) for i in input().split()] for i in range(n)]
    a = 0 ; b = 10**9 + 7
    ans = (-1,-1)
    candidate = -1
    while a <= b:
        mid = (a + b)//2
        bin_ans = find_pair(mid,data,m)
        if bin_ans[0] != -1 and bin_ans[1] != -1:
            ans = bin_ans
            candidate = mid
            a = mid + 1
        else:
            b = mid - 1
    backtracking(candidate,ans,data)

main()
