#!/env/python3


def main():
    a, b, c, d = [int(x) for x in input().split()]
    d += 1
    c -= 1
    ans = 0
    nums = []
    for i in range(70):
        for j in range(70):
            nums.append(a**i + b**j)
    nums.append(0)
    nums.sort()
    n = len(nums)
    for i in range(1, n):
        # print("%d %d == %d %d" % (c, d, nums[i-1], nums[i]))
        p = max(c, nums[i-1])
        q = min(d, nums[i])
        ans = max(ans, q-p-1)
    print(ans)


main()
