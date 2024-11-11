n = int(input())
s = input()
print(max([s[:i].count('I')-s[:i].count('D') for i in range(n+1)]))