from sys import stdin

numbers = stdin.readline().rstrip().split('+')
numbers.sort()
print('+'.join(numbers))