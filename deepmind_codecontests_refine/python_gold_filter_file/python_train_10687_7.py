# Read input and format
raw_input = input()

split_input = raw_input.split()
first_number = int(split_input[0])
substractions = int(split_input[1])
# print(first_number)
# print(substractions)

# Decrease one, unless last digit 0, then divide by 10
for iteration in range(substractions):
    numbers_last_digit = first_number % 10
    # print(f'last_digit: {numbers_last_digit}')
    if numbers_last_digit == 0:
        first_number = first_number // 10
        # print(f'after_iteration: {first_number}')
    else:
        first_number = first_number - 1
        # print(f'after_iteration: {first_number}')
# Print the solution
print(first_number)