
def tran(arr):
    p=max(arr)
    return p
if __name__ == '__main__':
    t = int(input())
    ans = []
    for i in range(t):
        arr = list(map(int, input().rstrip().split()))
        r = tran(arr)
        ans.append(r)
    for i in ans:
        print(i)
