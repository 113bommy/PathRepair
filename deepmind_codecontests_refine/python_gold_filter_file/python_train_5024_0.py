def solution(n, arr):

    nums = {}
    for el in arr:
        if el in nums:
            nums[el][1] += 1
        else:
            nums[el] = [el, 1]
    if 0 in nums:
        del nums[0]
        
    order_num = 2 ** 29
    del_els, k = [], 0

    while nums:
    
        for el in nums:
            if nums[el][0] >= order_num:
                k += nums[el][1]
                nums[el][0] -= order_num
                if not nums[el][0]:
                    del_els.append(el)
        for el in del_els:
            del nums[el]

        if k % 2:
            # print(k % 4 == 1, n - k)
            return "WIN" if (k % 4 == 1) or ((n - k) % 2) else "LOSE"

        k = 0
        del_els.clear()
        order_num >>= 1

    return "DRAW"
    


for test_i in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    print(solution(n, arr))