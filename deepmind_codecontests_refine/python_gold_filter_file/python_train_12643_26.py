
line = input()
x, y = map(int, line.strip().split())
n = int(input().strip())
n -= 1

result_table = [x, y, y - x, -x, -y, -y + x]

print((result_table[n % 6]) % (10**9 + 7))
