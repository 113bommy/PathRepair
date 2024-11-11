from sys import stdin, stdout

n = int(stdin.readline())
challengers = list(map(int, stdin.readline().split()))

l, r = 0, len(challengers) - 1

testf = sorted(challengers)
tests = sorted(challengers)[::-1]


l, r = 0, n - 1
while (l <= r and ((challengers[l] == testf[-1] and challengers[r] == tests[-1]) or (challengers[l] == tests[-1] and challengers[r] == testf[-1]))):
    testf.pop()
    tests.pop()
    l += 1
    r -= 1
        
for j in range(l + 1, r):
    if challengers[j] > max(challengers[l], challengers[r]) or challengers[j] < min(challengers[l], challengers[r]):
        stdout.write('3\n' + str(l + 1) + ' ' + str(j + 1) + ' ' + str(r + 1))
        break
else:
    stdout.write('0')