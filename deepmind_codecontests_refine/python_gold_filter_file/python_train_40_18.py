inp = input()
lt = inp.split(' ')
nums = list(map(int, lt))
a = nums[0]
b = nums[1]
h = a
while a >= b:
    g = a // b
    r = a % b
    h = h + g
    a = g + r
print(h)