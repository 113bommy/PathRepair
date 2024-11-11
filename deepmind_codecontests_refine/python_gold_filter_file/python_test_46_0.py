import sys

def solve(n, arr):
    answer = 0
    maxi = float("-inf")
    max_index = -1
    for i in range(n):
        if arr[i] >= maxi:
            maxi = arr[i]
            max_index = i
    i = n - 2
    current = arr[n - 1]
    if current != maxi:
        answer += 1
    while i > max_index:
        if arr[i] > current:
            answer += 1
            current = arr[i]
        i -= 1
    return answer

def main():
    test_case = int(sys.stdin.readline())
    for tc in range(test_case):
        n = int(sys.stdin.readline())
        arr = [int(a) for a in sys.stdin.readline().split()]
        print(solve(n, arr))

if __name__ == "__main__":
    main()