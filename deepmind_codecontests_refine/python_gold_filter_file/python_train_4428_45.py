n = int(input())

# First version
#a = 1
#for i in range(n):
#  a += (i + 1) * 6

# Second version
# (1 + 2 + ... + n) * 6 + 1
# = ((n + 1) * n / 2 * 6 + 1
a = (n + 1) * n * 3 + 1

print(int(a))
