import sys

fin = sys.stdin
fout = sys.stdout
s = fin.readline().strip()
res = [0] * len(s)

start = -1
end = len(s)
for i in range(len(s)):
    if s[i] == 'a':
        if start == -1:
            continue
        else:
            end = i - 1
            break
    elif start == -1:
        start = i
else:
    end = len(s) - 1
for i in range(len(s)):
    res[i] = s[i]
if start == -1:
    res[-1] = 'z'
else:
    for i in range(start, end + 1):
        res[i] = chr(ord(s[i]) - 1)
fout.write(''.join(res))
