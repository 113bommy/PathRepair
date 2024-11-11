n = int(input())
lst = [int(x) for x in input().split()]
x = len([elem for elem in lst if elem < 0])
values = sorted([abs(elem) for elem in lst])
result = sum(values)
if n % 2 == 0 and x % 2 == 1:
    result -= 2 * values[0]
print(result)
