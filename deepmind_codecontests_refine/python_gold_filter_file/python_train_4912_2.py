n = int(input())

nums = [ int(x) for x in input().split()]

# lowest is the smallest number is list, and divisor for 'mod' operation
lowest = 0
# count is the count of numbers in list 'nums' with common divisors
count=0
# q is the list of counts 
q = []
while nums:

    lowest = min(nums)
    for i in list(nums):
        # if lowest and i (element) are perfectly divisile, 
        # then they share a commnon divisor
        if(i%lowest == 0):
            count += 1
            # remove such elements from the main list
            nums.remove(i)
    # append the counts generated
    # len of these counts will be the number of colors needed
    q.append(count)
    # reset count for next iteration
    count = 0
# print the number of color buckets needed
print(len(q))






# one = two = three = five = seven = 0

# for num in nums:
#     if num % 7 == 0:
#         seven = 1
#     elif num % 5 == 0:
#         five = 1
#     elif num % 3 == 0:
#         three = 1
#     elif num % 2 == 0:
#         two = 1
#     elif num % 1 == 0:
#         one = 1

# print(one+two+three+five+seven)
    
    

