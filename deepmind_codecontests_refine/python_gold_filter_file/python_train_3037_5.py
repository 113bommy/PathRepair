length = int(input())
nums = [int(x) for x in input().split(" ")]
nums_sum = []
current_sum = 0
for x in nums:
    current_sum += x
    nums_sum.append(current_sum)
requests_size = int(input())

for i in range(0, requests_size):
    request = [int(x) for x in input().split(" ")]
    print((nums_sum[request[1] - 1] - (nums_sum[request[0] - 2] if request[0] - 2 >= 0 else 0))//10)
