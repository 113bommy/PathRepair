# Codeforces Submission
# User :    sudoSieg
# Time :    14:50:08
# Date :    21/10/2020

import io
import os
#input = lambda: io.BytesIO(os.read(0, os.fstat(0).st_size)).readline().strip()
valid = True
s = input()
ze = []
oe = []

for i, j in enumerate(s):
    if j == '0':
        if len(oe) != 0:
            x = oe.pop()
            x.append(i + 1)
            ze.append(x)
        else:
            ze.append([i + 1])
    else:
        if len(ze) != 0:
            x = ze.pop()
            x.append(i + 1)
            oe.append(x)
        else:
            print("-1")
            exit()
if len(oe) != 0:
    print(-1)
else:
    print(len(ze))
    for i in ze:
        print(len(i), end=' ')
        print(*i)
