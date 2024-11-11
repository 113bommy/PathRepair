import filecmp
import sys

FILE_IO = False


if FILE_IO:
    input_stream = open('input_test.txt')
    sys.stdout = open('current_output.txt', 'w')
else:
    input_stream = sys.stdin

t = int(input_stream.readline().split()[0])
for _ in range(t):
    s_length = int(input_stream.readline())
    s = input_stream.readline()
    l = 0
    r = s_length - 1
    palindrom = True
    while l < r:
        distance = abs(ord(s[l]) - ord(s[r]))
        if distance > 2 or distance == 1:
            palindrom = False
            break
        l += 1
        r -= 1
    if palindrom:
        print('YES')
    else:
        print('NO')

if FILE_IO:
    assert filecmp.cmp('current_output.txt', 'expected_output.txt', shallow=False) == True
